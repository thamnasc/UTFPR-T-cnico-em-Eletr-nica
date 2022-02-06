     //Paraolimpíadas
     //Thalita Maria do Nascimento
     //24/06/2016
     
     PImage photo;
     float y=0.0;
     int x;
     
     
     void setup (){
       size(1000,679);
       photo= loadImage("/home/todos/alunos/ct/a1849204/Área de Trabalho/programas/processing-2.2.1/mascot-both_new.gif");
     }
     
     void draw (){
       background(random(255),100,255,50); //background com cores aleatórias
       image(photo,0,y);
       y+=4.0;
       if(y>750){
         y=-700;
       }
       //Texto Informativo
       x=x+1;
         if (x>1000)  {
         x= -600 
       }
         
 
       textSize(40);
       text("Faltam 40 dias!",0,330);
       
     }
