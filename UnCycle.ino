void setup() {
Serial.begin(9600);
 pinMode(8, OUTPUT); 
}

 String data1, data2;

void loop() {
  
 Serial.println("Send a single character data to varify dataflow");  
 if(Serial.available()>0)
   {              
                  char Test = Serial.read();
                  Serial.println(Test); 
                  Serial.println("Send the data1");
                  while(data1.length() <= 3)
                  {
                    delay(100);
                    if(Serial.available()>0)
                      { char str1 = Serial.read();
                        data1 += str1;     
                        Serial.println("Yes data1 received"); 
                        Serial.println(data1);
                          }
                          
                    else
                       { Serial.println("Data1 is not received");
                         delay(4000);
                           }
                    
                  }       
                                                            
                   
                  Serial.println("Send the second data2");
                  while(data2.length() <= 3)
                  {   delay(100);
                
                      if(Serial.available()>0)
                        { char str2 = Serial.read();
                          data2 += str2;
                          Serial.println("Yes data2 is received");
                          Serial.println(data2); 
                             if(data1 == data2)
                                { Serial.println("Data Mathed");
                                  digitalWrite(8,HIGH); 
                                  Serial.println("Lock is opened"); 
                                          }
                 
                              else
                                 { Serial.println("Data is Not Mathed");
                                   Serial.println("Lock Will Remain Closed");
                                   
                                   digitalWrite(8,LOW); 
                                   
                                       }
                         }
                  
                         else
                            { Serial.println("Data2 not is received");
                              delay(4000);
                                    } 
                   } 
        
      
   }
   data1 = "";
   data2 = "";
   delay(10000);
}
