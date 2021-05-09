

// include the library code:
#include <LiquidCrystal.h>
#define OKb 6
#define UPb 7
#define DOWNb 8
#define CANCELb 9
#define bcheck OK=digitalRead(OKb);\
    UP=digitalRead(UPb);\
    DOWN=digitalRead(DOWNb);\
    CANCEL=digitalRead(CANCELb);


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
Serial.begin(9600);
  pinMode(OKb, INPUT_PULLUP);
  digitalWrite(OKb, HIGH);
  pinMode(UPb, INPUT_PULLUP);
  digitalWrite(UPb, HIGH);
  pinMode(DOWNb, INPUT_PULLUP);
  digitalWrite(DOWNb, HIGH);

  pinMode(CANCELb, INPUT_PULLUP);
  digitalWrite(CANCELb, HIGH);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

char *Week[] = {"0","0","0","0","0","0","0"};
int countdown[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int RTcount[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char *StepCount[25]={"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
byte MaxMenu=0;

void loop() {
  int n = 7;
  int openMenu = 0;
  bool OK = digitalRead(OKb);
  bool UP = digitalRead(UPb);
  bool DOWN = digitalRead(DOWNb);
  bool CANCEL = digitalRead(CANCELb);
  bool iniStep;
 char SCEStep;
  char OK1 = 0;
  char *menu[] =
  { "Timer          ",
    "Scheduling     ",
    "Repeat         ",
    "Remove Sched.  ",
    "Reset          ",
    "               "
  };
  
  byte setTime;
  byte RTC;
  byte countT;

  char *State[] = {"I","W"};
  byte Pointer[8] = {
    0b10000,
    0b11000,
    0b11100,
    0b11111,
    0b11111,
    0b11100,
    0b11000,
    0b10000
  };
  byte Blank[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };
  byte Timer[8] = {
    0b10001,
    0b01010,
    0b01110,
    0b11011,
    0b10001,
    0b11011,
    0b01110,
    0b00000
  };
  byte UPS[8] = {
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00000
  };
  byte DOWNS[8] = {
    0b00000,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b10101,
    0b01110,
    0b00100
  };
  byte Step[8] = {
    0b10000,
    0b10010,
    0b10100,
    0b11001,
    0b10011,
    0b00101,
    0b01001,
    0b00001
  };
  byte RTime[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };
  byte Right[8] = {
    0b00000,
    0b00001,
    0b10010,
    0b10100,
    0b11000,
    0b10000,
    0b00000,
    0b00000
  };
  byte Wrong[8] = {
    0b00000,
    0b10001,
    0b01010,
    0b00100,
    0b01010,
    0b10001,
    0b00000,
    0b00000
  };
  
  
  lcd.createChar(0, Pointer);
  lcd.createChar(1, Wrong);
  lcd.createChar(2, Timer);
  lcd.createChar(3, Step);
  lcd.createChar(4, UPS);
  lcd.createChar(5, DOWNS);
  lcd.createChar(6, RTime);
  lcd.createChar(7, Right);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));   //0 manje pointer
  lcd.setCursor( 1, 0);
  lcd.print("MENU           ");
  lcd.setCursor( 0, 1);
  lcd.write(byte(2));
  lcd.setCursor( 1, 1);
  lcd.print("HH:MM   STATE:");
   lcd.setCursor( 16, 1);
  lcd.print(State[0]);
  



  if (OK == 0)
  { delay(100);
    if (OK == 0)
    {
      openMenu = 7;
      Serial.print("Welcome");
      delay(300);
    }
  }


 for (int i = 0; openMenu == 7;)
  { lcd.clear();
  Serial.println(i);
    lcd.setCursor(0, 0);
    lcd.write(byte(0));  
    lcd.setCursor( 0, 1);
    lcd.print(" ");
    bcheck
    lcd.setCursor(1, 0);
    lcd.print(menu[i]);
    lcd.setCursor(1, 1);
    lcd.print(menu[i + 1]);
      if (DOWN == 0)
      { delay(100);
        if (DOWN == 0)
        {
          if (i < 4)
          {
            i = i + 1; digitalWrite(13, HIGH);
            delay(300);
          }
        }
      }
    if (CANCEL == 0)
    { delay(100);
      if (CANCEL == 0)
      {
        openMenu = 6;
        delay(300);
        lcd.setCursor( 0, 1);
    lcd.print(" ");
      }
    }
    if (UP == 0)
    { delay(100);
      if (UP == 0)
      {
        --i; digitalWrite(13, HIGH);

        delay(300);

      }
    }
    if (OK == 0)
    { delay(100);
      if (OK == 0)
      {char n=i;
        OK1 = 2;
        i=0;
        setTime = 1;
        
       byte j=0,k=0,l=0,m=0;
        delay(300); lcd.clear();
        /////////////////////Sub Menu Timer
        while (n==0 && OK1 == 2)

        {
          
         lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("   HH:MM    STEP");
          int Timer[2] = {0, 0};

          while(setTime==1)
          {
             bcheck
           
            if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=4;OK1=1;}}
            
            if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              {
                i = i + 1; digitalWrite(13, HIGH);
                delay(300);

              }
            }//DOWN
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --i; digitalWrite(13, HIGH);

                delay(300);

              }
            }//UP
            if (i > 23)
            {
              i = 0;
            }
            if (i < 0)
            {
              i = 23;
            }
         if(i<10)
         {   lcd.setCursor(3, 1);
            lcd.print("0");
            lcd.setCursor(4,1);
            lcd.print(i);}
            else
            {lcd.setCursor(3, 1);
            lcd.print(i);}

            delay(100);
        if (OK == 0)
        { delay(100);
              if (OK == 0)
              {
                Timer[0] = i;
                setTime = 2;
              }
            }

          }
          lcd.setCursor(5, 1);
          lcd.print(":");
          i=Timer[1];

         while(setTime==2)
          {
             bcheck
            if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              {
                i = i + 1; digitalWrite(13, HIGH);
                delay(300);

              }
            }
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --i; digitalWrite(13, HIGH);

                delay(300);
              }
            }
            if (i > 59)
            {
              i = 0;
            }
            if (i < 0)
            {
              i = 59;
            }

        if(i<10)
         {   lcd.setCursor(6, 1);
            lcd.print("0");
            lcd.setCursor(7,1);
            lcd.print(i);}
            else
            {lcd.setCursor(6, 1);
            lcd.print(i);}

            delay(100);
            if (OK == 0)
            { delay(100);
              if (OK == 0)
              { Timer[1] = i;setTime=3;
              if(Timer[1]==0 && Timer[2]==0)
              {lcd.clear();
              lcd.setCursor(0,0);
                lcd.print("Timer can be ");
                lcd.setCursor(0,1);
                lcd.print("00:00 Set Again");
                delay(2000);
                setTime=1;}
              }}
     if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=1;i=Timer[0];}}

              }//while 2
  
while(setTime==3)
{bcheck
 if (UP == 0)
            { delay(100);
              if (UP == 0)
              { iniStep =1;
              lcd.setCursor(12,1);
              lcd.print("  UP");
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { iniStep =0;
              lcd.setCursor(12,1);
              lcd.print("DOWN");
              }}
               if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=2;i=Timer[1];}}
     if (OK == 0)
            { delay(100);
              if (OK == 0)
              { setTime=4;OK1=3;
              }}
 }

            }//While for menu 1
        
        
        while (n==1 && OK1 == 2)

        {
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.write(byte(6));
          lcd.setCursor(1,0);
          lcd.print("HH:MM ");
          lcd.setCursor(7,0);
          lcd.write(byte(2));
          lcd.setCursor(8,0);
          lcd.print("HH:MM  ");
          lcd.setCursor(15,0);
          lcd.write(byte(3));
          

        while(setTime==1)
          {
             bcheck
           
            if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=7;OK1=1;}}
            
    if (DOWN == 0)
      { delay(100);
        if (DOWN == 0)
          {
           i = i + 1; digitalWrite(13, HIGH);
             delay(300);
              }
            }//DOWN
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --i; digitalWrite(13, HIGH);
                 delay(300);

              }
            }//UP
            if (i > 23)
            {
              i = 0;
            }
            if (i < 0)
            {
              i = 23;
            }
         if(i<10)
         {  lcd.setCursor(1, 1);
            lcd.print("0");
            lcd.setCursor(2,1);
            lcd.print(i);}
            else
            {lcd.setCursor(1, 1);
            lcd.print(i);}

            delay(100);
        if (OK == 0)
        { delay(100);
              if (OK == 0)
              {
                RTC = i*60;
                setTime = 2;
              }
            }

          }
          lcd.setCursor(3, 1);
          lcd.print(":");
          

         while(setTime==2)
          {
             bcheck
            if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              {
                j = j + 1; digitalWrite(13, HIGH);
                delay(300);

              }
            }
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --j; digitalWrite(13, HIGH);

                delay(300);
              }
            }
            if (j > 59)
            {
              j = 0;
            }
            if (j < 0)
            {
              j = 59;
            }

        if(j<10)
         {   lcd.setCursor(4, 1);
            lcd.print("0");
            lcd.setCursor(5,1);
            lcd.print(j);}
            else
            {lcd.setCursor(4, 1);
            lcd.print(j);}

            delay(100);
            if (OK == 0)
            { delay(100);
              if (OK == 0)
              { RTC = RTC+j;setTime=3;
              }}
     if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=1;i=hour(RTC);}}

              }//while 2
              
        while(setTime==3)
          {
             bcheck
           
            if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=2;j=minute(RTC);}}
            
    if (DOWN == 0)
      { delay(100);
        if (DOWN == 0)
          {
           k = k + 1; digitalWrite(13, HIGH);
             delay(300);
              }
            }//DOWN
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --k; digitalWrite(13, HIGH);
                 delay(300);

              }
            }//UP
            if (k > 23)
            {
              k = 0;
            }
            if (k < 0)
            {
              k = 23;
            }
         if(k<10)
         {  lcd.setCursor(8, 1);
            lcd.print("0");
            lcd.setCursor(9,1);
            lcd.print(k);}
            else
            {lcd.setCursor(8, 1);
            lcd.print(k);}

            delay(100);
        if (OK == 0)
        { delay(100);
              if (OK == 0)
              {
                countT = k*60;
                setTime = 4;
              }
            }

          }
          lcd.setCursor(10, 1);
          lcd.print(":");
          

         while(setTime==4)
          {
             bcheck
            if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              {
                l = l + 1; digitalWrite(13, HIGH);
                delay(300);

              }
            }
            if (UP == 0)
            { delay(100);
              if (UP == 0)
              {
                --l; digitalWrite(13, HIGH);

                delay(300);
              }
            }
            if (l> 59)
            {
              l = 0;
            }
            if (l < 0)
            {
              l = 59;
            }

        if(l<10)
         {   lcd.setCursor(11, 1);
            lcd.print("0");
            lcd.setCursor(12,1);
            lcd.print(l);}
            else
            {lcd.setCursor(11, 1);
            lcd.print(l);}

            delay(100);
            if (OK == 0)
            { delay(100);
              if (OK == 0)
              { countT = countT+l;setTime=5;
              if(countT==0)
              {lcd.clear();
              lcd.setCursor(0,0);
                lcd.print("Timer can be ");
                lcd.setCursor(0,1);
                lcd.print("00:00 Set Again");
                delay(2000);
                setTime=1;}
                for(m=0;m<100 && countT!=0;)
                {if(countdown[m]==0)
                   {MaxMenu=m;
                   countdown[m]=countT;
                   RTcount[m]=RTC;
                   break;}
                else
                {m=m+1;}
                
                
                }
              }}
     if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=1;k=hour(countT);}}

              }//while 2
  
          while(setTime==5)
            {bcheck
           if (UP == 0)
            { delay(100);
              if (UP == 0)
              { SCEStep ="1";
              lcd.setCursor(15,1);
              lcd.write(byte(4));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { SCEStep ="0";
              lcd.setCursor(15,1);
              lcd.write(byte(5));
              }}
               if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=4;l=hour(countT);}}
     if (OK == 0)
            { delay(100);
              if (OK == 0)
              { setTime=6;OK1=3;
              StepCount[m]=SCEStep;
              }}
 }

            }//While for menu 2
            
        
        while((n==2) && (OK1 == 2))
        {
        
             lcd.setCursor(2,0);
             lcd.print(" SMTWTFS");

              for(j=0;j<7;++j)
              {
                lcd.setCursor(3+j,1);
                if(Week[j]=="1")
                {lcd.write(byte(7));}
                if(Week[j]=="0")
                {lcd.write(byte(1));}
              }

   /*         for(i=7;i>=1;){  
    *          while(setTime==i)
           {
               
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[i-1]="1";
              
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[i-1] ="0";
              
              }}
               if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime--;i--;
     }}
     if (OK == 0)
            { delay(100);
              if (OK == 0)
              {
             setTime++;
            
              }}
           }            
*/
           while(setTime==7)
           { lcd.setCursor(2+setTime,1);
             lcd.blink();
              bcheck 
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[6]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[6] ="0";    
                lcd.write(byte(1));
              
              }}
               if(CANCEL == 0)
     {delay(100);
     if(CANCEL == 0)
     {setTime=6;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=8;OK1=1;lcd.noBlink();
            
              }}
           }
           while(setTime==6)
           {lcd.setCursor(2+setTime,1);
             lcd.blink();
              bcheck 
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[5]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[5] ="0";
              lcd.write(byte(1));
              }}
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=5;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=7;
            
              }}
           }            
           while(setTime==5)
           {lcd.setCursor(2+setTime,1);
             lcd.blink();
               bcheck
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[4]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[4] ="0";
              lcd.write(byte(1));
              }}
              
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=4;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=6;
            
              }}
           }
           while(setTime==4)
           {lcd.setCursor(2+setTime,1);
             lcd.blink();
               bcheck
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[3]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[3] ="0";
              lcd.write(byte(1));
              }}
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=3;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=5;
            
              }}
           }            
           while(setTime==3)
           {lcd.setCursor(2+setTime,1);
             lcd.blink();
               bcheck
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[2]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[2] ="0";
              lcd.write(byte(1));
              }}
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=2;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=4;
            
              }}
           }            
           while(setTime==2)
           {bcheck
               lcd.setCursor(2+setTime,1);
             lcd.blink();
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[1]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[1] ="0";
              lcd.write(byte(1));
              }}
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=1;
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=3;
            
              }}
           }     
           while(setTime==1)
           {bcheck
               lcd.setCursor(2+setTime,1);
             lcd.blink();
             if (UP == 0)
            { delay(100);
              if (UP == 0)
        { Week[0]="1";
              lcd.write(byte(7));
              }}
               if (DOWN == 0)
            { delay(100);
              if (DOWN == 0)
              { Week[0] ="0";
              lcd.write(byte(1));
              }}
               if(CANCEL == 0)
     {delay(300);
     if(CANCEL == 0)
     {setTime=0;OK1=1;lcd.noBlink();
     }}
     if (OK == 0)
            { delay(300);
              if (OK == 0)
              {
             setTime=2;
            
              }}
           }   //////////////////////////////         
                         
            }//While for menu 3

          }
        while((n==4) && (OK1 == 2))
        { Serial.print("CountdownValue=");
          Serial.println(countdown[0]);
         // if(countdown[0]!=0)
         // {
   /*         for(byte j=0;j<=MaxMenu && OK1==2 && countdown[0]!=0 ;)
        {bcheck
          lcd.setCursor(0,0);
          lcd.print(byte(0));
          lcd.setCursor(1,1);
          lcd.print(byte(6));
          lcd.setCursor(1,0);
          lcd.print(byte(6));        
          lcd.setCursor(4,0);
          lcd.print(":");  
          lcd.setCursor(4,1);
          lcd.print(":"); 
          lcd.setCursor(7,0);
          lcd.print(" ");  
          lcd.setCursor(7,1);
          lcd.print(" ");   
          lcd.setCursor(8,1);
          lcd.print(byte(2));
          lcd.setCursor(8,0);
          lcd.print(byte(2));
          lcd.setCursor(11,0);
          lcd.print(":");  
          lcd.setCursor(11,1);
          lcd.print(":"); 
          lcd.setCursor(14,0);
          lcd.print(" ");  
          lcd.setCursor(14,1);
          lcd.print(" ");
      
          lcd.setCursor(2,0);
          if(hour(RTcount[j])<10)  
          {lcd.print("0");lcd.setCursor(3,0);
          lcd.print(hour(RTcount[j]));}
          else
          {lcd.print(hour(RTcount[j]));}
          lcd.setCursor(5,0);
          if(minute(RTcount[j])<10)
          {lcd.print("0");lcd.setCursor(6,0);
          lcd.print(minute(RTcount[j]));}
          else
          {lcd.print(minute(RTcount[j]));}
          lcd.setCursor(9,0);
          if(hour(countdown[j])<10)
          {lcd.print("0");lcd.setCursor(10,0);
          lcd.print(hour(countdown[j]));}
          else
          {lcd.print(hour(countdown[j]));}
          lcd.setCursor(12,0);
          if(minute(RTcount[j])<10)
          {lcd.print("0");lcd.setCursor(13,0);
          lcd.print(minute(countdown[j]));}
          else
          {lcd.print(minute(countdown[j]));}
          if((j+1)<=MaxMenu)
          {
          lcd.setCursor(2,1);
          if(hour(RTcount[j+1])<10)
          {lcd.print("0");lcd.setCursor(3,1);
          lcd.print(hour(RTcount[j+1]));}
          else
          {lcd.print(hour(RTcount[j+1]));}
          lcd.setCursor(5,1);
          if(minute(RTcount[j+1])<10)
          {lcd.print("0");lcd.setCursor(6,1);
          lcd.print(minute(RTcount[j+1]));}
          else
          {lcd.print(minute(RTcount[j+1]));}
          lcd.setCursor(9,1);
          if(hour(countdown[j+1])<10)
          {lcd.print("0");lcd.setCursor(10,1);
          lcd.print(hour(countdown[j+1]));}
          else
          {lcd.print(hour(countdown[j+1]));}
          lcd.setCursor(12,1);
          if(minute(RTcount[j+1])<10)
          {lcd.print("0");lcd.setCursor(13,1);
          lcd.print(minute(countdown[j+1]));}
          else
          {lcd.print(minute(countdown[j+1]));}
          }
          else if((j+1)>MaxMenu)
          {lcd.setCursor(0,1);
          lcd.print("       END     ");}
          
         
        
        if (DOWN == 0)
      { delay(300);
        if (DOWN == 0)
        {
            j = j + 1; digitalWrite(13, HIGH);
            delay(300);
          
        }
      }
    if (CANCEL == 0)
    { delay(300);
      if (CANCEL == 0)
      {
        OK1=3;
        delay(300);
      }
    }
    if (UP == 0)
    { delay(300);
      if (UP == 0)
      {
        --j; digitalWrite(13, HIGH);

        delay(300);

      }
    }
  /*  if (OK == 0)
    { delay(300);
      if (OK == 0)
      { OK1 = 2;
       
    
       }}
        
      if(j>MaxMenu)
      {j=MaxMenu;}
      if(j<0)
      {j=0;}  
        
        
        
        
        
        }
       // }
       if (countdown[0]==0)
        {lcd.clear();
          lcd.setCursor(0,0);
        lcd.print("No record found");
        Serial.print("No record found");
        delay(30000);
        OK1=3;}*/
        }
        }//OK


        i = Check(i);
      }
    






    }//Last blacket






    byte Check(int i)
    { if (i > 5)
      {
        i = 4;
      }
      if (i < 0)
      {
        i = 0;
      }
      return i;
    }


   byte minute(byte m)
   {
     return (m%60);
   }
   byte hour(byte m)
   {
     return (m/60);
   }
