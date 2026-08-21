# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

#define N 4

int main () {

   pid_t pid = -1;

   for(int i = 0; i<N ; i++){
      if(pid != 0){
         pid = fork ();
      }  
      if(pid < 0){
         printf("ERRO");
      }
   }
   
   if(pid != 0){
      printf("EU SOU O PAI MEU PID É: %d\n", getpid());
      wait(NULL);
   }
   else{
      printf("Eu sou o filho de PID: %d, MEU PAI É: %d\n", getpid(), getppid());
   }


   return 0;
}