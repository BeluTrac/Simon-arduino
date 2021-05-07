
int pasos[50]; 

void setup() {
Serial.begin(9600);

pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);

pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);

pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
 
 
}

int whboton()
{
  int bot = 0;
  //delay(300);
  
  if(digitalRead(2)==HIGH){
    bot = 2;
  }

  if(digitalRead(3)==HIGH)
  {
    bot = 3;
  }

  if(digitalRead(4)==HIGH)
  {
    bot = 4;
  }

  if(digitalRead(5)== HIGH)
  {
    bot = 5;
  }


  Serial.println("Bot");
  Serial.println(bot);
  return bot;
}

void simon (int n,bool  correcto)
{
    pasos[n] = random(2,6);

    Serial.println("Random");
    Serial.println(pasos[n]);

     for( int j=0; j<=n; j++) //enciende los leds correspondientes a esa instancia
     {
       digitalWrite( pasos[j]+4 , HIGH);
       delay(1000); 
       digitalWrite( pasos[j]+4 , LOW); 
       delay(500);
     }
 delay(300);

for( int j=0; j<=n; j++)
{
   int bot=0;

   Serial.println("N");
   Serial.println(n);

   if(correcto)
   {
     //bot = whboton(); 

      while (bot ==0)
      {
        delay(100);
        bot = whboton();
      }

      Serial.println("Bot While");
      Serial.println(bot);
      
     digitalWrite(bot+4 , HIGH);
     delay( 500);
     digitalWrite ( bot+4, LOW);

      if ( pasos[j]!= bot) // Puede haber problemas porque siempre este mandando 0, si prende el boton rojo mucho tiempo
      {
          correcto = false; 
          digitalWrite( 10 , HIGH);
          delay (1000);
          digitalWrite( 10 , LOW);
      }
      else
      {
        digitalWrite( 11 , HIGH);
          delay (500);
          digitalWrite(11 , LOW);
      }
   }
}

if(correcto)
{
  n++;
  simon(n, correcto);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  
   simon (0, true);
     
}
