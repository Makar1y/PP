#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int course_to_num(char course[]) {
	if (strcmp("Algebra", course) == 0)
		return 0;
	
	else if (strcmp("Computer programming", course) == 0)
		return 1;

	else if (strcmp("Operating systems", course) == 0)
		return 2;

	else if (strcmp("Physics", course) == 0)
		return 3;

	else if (strcmp("Philosophy", course) == 0)
		return 4;

	else if (strcmp("Calculus", course) == 0)
		return 5;

	else if (strcmp("Set theory", course) == 0)
		return 6;

	else if (strcmp("Algorithms", course) == 0)
		return 7;

	else if (strcmp("Discrete mathematics", course) == 0)
		return 8;

	else if (strcmp("Computer networks", course) == 0)
		return 9;
	else
		return 100; // error
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
		int courses_counter[10] = {  // for courses counting
				0, // Algebra
				0, // Computer programming
				0, // Operating systems
				0, // Physics
				0, // Philosophy
				0, // Calculus
				0, // Set theory
				0, // Algorithms
				0, // Discrete mathematics
				0, // Computer networks
			};

		for (int i = 0, current_max = 0; i < size; ++i) {
			Student student = students[i];

			int algebra = 0,
			 computer_programming = 0, 
			 operating_systems = 0, 
			 physics = 0, 
			 philosophy = 0,
			 calculus=0, 
			 set_theory=0, 
			 algorithms=0, 
			 discrete_mathematics=0, 
			 computer_networks=0;

			for (int i = 0; i < student.load; ++i){
				if (strcmp("Algebra", student.courses[i]) == 0 && !algebra) {
					courses_counter[0]++;
					algebra++;
				}
				
				else if (strcmp("Computer programming", student.courses[i]) == 0 && !computer_programming) {
					courses_counter[1]++;
					computer_programming++;
				}

				else if (strcmp("Operating systems", student.courses[i]) == 0 && !operating_systems) {
					courses_counter[2]++;
					operating_systems++;
				}

				else if (strcmp("Physics", student.courses[i]) == 0 && !physics) {
					courses_counter[3]++;
					physics++;
				}

				else if (strcmp("Philosophy", student.courses[i]) == 0 && !philosophy) {
					courses_counter[4]++;
					philosophy++;
				}

				else if (strcmp("Calculus", student.courses[i]) == 0 && !calculus) {
					courses_counter[5]++;
					calculus++;
				}

				else if (strcmp("Set theory", student.courses[i]) == 0 && !set_theory) {
					courses_counter[6]++;
					set_theory++;
				}

				else if (strcmp("Algorithms", student.courses[i]) == 0 && !algorithms) {
					courses_counter[7]++;
					algorithms++;
				}

				else if (strcmp("Discrete mathematics", student.courses[i]) == 0 && !discrete_mathematics) {
					courses_counter[8]++;
					discrete_mathematics++;
				}

				else if (strcmp("Computer networks", student.courses[i]) == 0 && !computer_networks) {
					courses_counter[9]++;
					computer_networks++;
				}
			}
		}
		


		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if( 1 ){ // *** first filter, conditions on the student
				// printf went down :)
				int anotherDemo = 0; // for counting courses/grades
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if( courses_counter[course_to_num(s.courses[i])] != 1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						// printf("Course: %s Grade: %d\n", s.courses[i], s.grades[i]);
					}
				}
				// printf("Languages: %s\n\n", s.languages);
						
				if (anotherDemo == s.load) {// *** third filter, various other conditions		
					printf("\n%s %s Course: %d Average: %f Load: %d", s.name, s.surname, s.course, s.average, s.load); // print student data	
					++counterDemo; // counting students
            	}
			}
		}
		printf("\n\nFilter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}