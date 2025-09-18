#include <stdio.h>
#include <stdlib.h>

int language_counter(char languages[]) {
	int counter = 1;
	for (int i = 0; i<100; i++) {
		if (languages[i] == ' ')
			counter++;
	}
	return counter;
}

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded successfully\n", size);
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		int max_languages = 0; // for languages count comparison
		for (int i = 0, current_max = 0; i < size; ++i) {
			Student student = students[i];
			current_max = language_counter(student.languages);
			if (current_max > max_languages)
				max_languages = current_max;
		}
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if( max_languages == language_counter(s.languages) ){ // *** first filter, conditions on the student
				printf("%s %s Course: %d Average: %f Load: %d\n", s.name, s.surname, s.course, s.average, s.load); // print student data
				int anotherDemo = 0; // for counting courses/grades
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if(1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						// printf("Course: %s Grade: %d ", s.courses[i], s.grades[i]);
					}
				}
				printf("Languages: %s\n\n", s.languages);
						
				if (anotherDemo == s.load) {// *** third filter, various other conditions			
					++counterDemo; // counting students
            	}
			}
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}