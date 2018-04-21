#include<stdio.h> 
#include<unistd.h>
#include<stdlib.h> 
#include<string.h> 
#include<pthread.h> 
#include<semaphore.h>
#define SEAT_NUM 3
#define MAX_SLEEP 5 sem_t sem_stu; sem_t sem_ta; 
pthread_mutex_t mutex; 
int chair[3]; 
int count=0; 
int next_seat=0; 
int next_teach=0; 
void rand_sleep(void); 
void* stu_programming(void* stu_id); 
void* ta_teaching(); 
//int argc, char argv
int main() 
{ 
pthread_t students;
pthread_t ta; 
int student_ids; 
int student_num; 
int i; 
printf("enter no of students"); 
scanf("%d",&student_num); 
students = (pthread_t)malloc(sizeof(pthread_t) * student_num); 
student_ids = (int)malloc(sizeof(int)student_num); 
memset(student_ids, 0,student_num); sem_init(&sem_stu,0,0); 
sem_init(&sem_ta,0,1); srand(time(null)); 
pthread_mutex_init(&mutex, null); 
for(i=0; i<student_num; i++)
 {
  student_ids[i] = i+1; 
  pthread_create(&students[i], null,stu_programming,(void) &student_ids[i]);
 }
    pthread_join(ta, null); 
	for(i=0; i<student_num;i++) 
	{
	 pthread_join(ta, null); 
    } 
	 for(i=0;i<student_num;i++) 
	 {
	  pthread_join(students[i], null); 
	 }
	   return 0; 
 }
void stu_programming(void stu_id)
 {
	 int id = (int)stu_id;
	 printf(" student %d is working", id);
	 while(1) {
			 rand_sleep();
			  pthread_mutex_lock(&mutex); 
			  if(count < num_seat) { 
			  chair[next_seat] = id; 
			count++;
			  printf("student %d is waiting", id); 
			  printf("waiting students : [1]%d [2] %d [3] %d \n",chair[0],chair[1],chair[2]); 
			  next_seat =(next_seat+1)% num_seat; 
			  pthread_mutex_unlock(&mutex);
			   sem_post(&sem_stu);
			    sem_wait(&sem_ta); 
				} 
				else 
				{ 
				pthread_mutex_unlock(&mutex);
			 printf("chairs are full. student %d is programming\n",id); 
			 } 
			 } 
			 }
 void* ta_teaching()
	 { 
		while(1) 
		{
		 sem_wait(&sem_stu);
		 pthread_mutex_lock(&mutex); 
		 printf(" teacher is teaching student %d\n",);
		 chair[next_teach]); 
		 chair[next_teach]=0;
		 count--; 
		 printf(" students waiting are [1] %d [2] %d [3] %d\n", chair[0],chair[1],chair[2]); 
		 next_teach = (next_teach + 1)% SEAT_NUM; rand_sleep();
		 printf(" teaching is completed\n");
		 pthread_mutex_unlock(&mutex);
		 sem_post(&sem_ta); 
			 } 
	}
void rand_sleep(void)
{ 
int time= rand() % MAX_SLEEP +1; sleep(time);
}
