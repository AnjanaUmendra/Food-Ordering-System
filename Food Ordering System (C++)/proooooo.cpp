#include <iostream.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <iomanip.h>
#include <fstream> 
#include <stdlib.h>
#include <sstream>


using namespace std;

double getTotal_rice(int quantity1,int itemNo2);
double getTotal_kottu(int quantity1,int itemNo2);
double getChange(float MainTotal,float cash);

int main()
{
	
	string line,choice,menu1,itemN,quantity;
	char name[100];
	char y,Y,n,N,letter;
	int size,i,m,Tot,num,foodamt=8,itemNo=0,count,intchoice,menu2,count1,itemNo2,count2,quantity1,count3;
	float MainTotal=0,MainTotal1=0,MainTotal12=0,cash;
    string rice[7]={"Chicken Fried Rice","Egg Fried Rice    ","Seafood Fried Rice","Vito Special      ","Chicken Biryani   ","Shrimps Biryani   ","Mutton Biryani    "};
    string kottu[7]={"Chicken Kottu","EGG Kottu    ","Cheese Kottu ","Special Kottu","Beef Kottu","vegi Kottu","Mixed Kottu"};
    float priceR[7]={550,450,750,850,450,450,650};
    float priceK[7]={400,300,550,800,600,250,700};
    
        
          SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 1);
          HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
   	      SetConsoleTextAttribute(h,0xE);
           cout<<std::fixed<<std::setprecision(2);
          start:                                       //menu1
   	      system("CLS");
	       cout<<"\n\t\t\t  ============================================================\n"<<endl;
	      SetConsoleTextAttribute(h, 11);
  	      cout<<"\t\t\t\t\t\t VITO FOOD Place\t\t\t\t\t\t "<<endl;
  	      SetConsoleTextAttribute(h,0xF);
  	      SetConsoleTextAttribute(h,0xE);
  	       cout<<"\n\t\t\t  ============================================================\n"<<endl;
  	      SetConsoleTextAttribute(h,0xF);
  	      
  	     
	      cout<<"\t\t\t Please Enter Your Name: "  ;
	      cin.getline(name,100);
	      cout<<"\n\t\t\tHello "<<name<<"...!. "<<"Welcome to Vito Food Place"<<endl;
	      cout<<"\t\t\t------------------------------------------------------------------"<<endl;

           again1:
	       cout<<"\n\t\t\t\tWhat would you like to order?"<<endl<<endl;
	       cout<<"\n\t\t\t\t 1. Rice Menu "<<endl;
	       cout<<"\t\t\t\t 2. Kottu Menu"<<endl;
	 
	       cout<<"\n\n\t\t\t\t Enter Your choice (1 or 2) : ";
           cin>>menu1;
	  
	              for (int i=0;i<menu1.length();i++) 
	 	            {
		             if (isdigit(menu1[i]) == false) 
		                {
			             count1=1;
					  		
			             break;
		                }
		             else
		                {
		                  count1=0;
		                }
		
		            }
		          if(count1==0)
                    {
	                 stringstream con(menu1);
		             con >> menu2;
   
	                   if(menu2==1)                     //Rice menu
                        {
        	           ricemenu:
                       system("CLS");
        
                         cout<<"\n\t\t\t  ==============================================================\n"<<endl;
                         SetConsoleTextAttribute(h, 10);
    	                 cout<<"\t\t\t\t\t\t___Rice Menu___"<<endl;
    	                 SetConsoleTextAttribute(h,0xF);
						 cout<<"\n\t\t\t  ==============================================================\n\n"<<endl;  
						 cout<<"\n\t\t\t  ------------------------------------------------------------------"<<endl<<endl;     
		                 cout<<"\t\t\t\t\tFood\t\t\t  Prize\n";
       	                 cout<<"\t\t\t  ------------------------------------------------------------------"<<endl<<endl;
       	                 SetConsoleTextAttribute(h,0xF);
			   
  	                         for(i=0;i<7;i++)                                                                      //for loop for Display rice Menu
  	                          {  
								 SetConsoleTextAttribute(h, 13);	 
                                cout<<"\t\t\t\t"<<i+1<<". "<<rice[i]<<"  :         RS. "<<priceR[i]<<endl;
                                SetConsoleTextAttribute(h,0xF); 
        
  	                          }
  	                            cout<<"\n\t\t\t  ---------------------------------------------------------------"<<endl;
 
                        again2:
  	                    cout<<"\n\n\t\tEnter Your Choice No\t\t     : ";
        	            cin>>itemN;
        	                   for (int i=0;i<itemN.length();i++) 
	        	               {
	        	                 if (isdigit(itemN[i]) == false) 
	         	                   {
		    	                  count2=1;
					  		
		     	                 break;
	      	                       }
	     	                     else
		                           {
	      	                    count2=0;
		                           }
		
	     	                    }
	    	                      if(count2==0)
                                    {
	                                  stringstream con(itemN);
	                                  con >> itemNo2;
   
        	
        	                          while(itemNo2>0)
        	                           {
     		                             if(itemNo2<foodamt)
       		                               {
       		                               	 SetConsoleTextAttribute(h, 13);
		                                     cout<<"\n\n\tYour Order =>\t  "<<itemNo2<<". "<<rice[itemNo2-1]<<"\t     :RS. "<<priceR[itemNo2-1]<<endl;
		                                      SetConsoleTextAttribute(h,0xF);
		                                     quant:
                                             cout<<"\n\t\t\tPleace enter Your quantity   : ";
                                             cin>>quantity;
                                             for (int i=0;i<quantity.length();i++) 
	        	                               {
	        	                               if (isdigit(quantity[i]) == false) 
	         	                                 {
		    	                                 count3=1;
					  		                     break;
	      	                                     }
	     	                                  else
		                                         {
	      	                                      count3=0;
		                                         }
		
	     	                                     }
	    	                                   if(count3==0)
                                                 {
	                                              stringstream con(quantity);
	                                              con >> quantity1;
	                      
	                                                if(quantity1>0)
	                      {
                      	  ofstream myFile("Bill.txt",ios::app);
		                  myFile<<"\n\n\t\t\t\t "<<rice[itemNo2-1]<<"\t\t"<<quantity<<"\t\t"<<priceR[itemNo2-1]<<endl;
		                  myFile.close();  
						          
                          MainTotal1= getTotal_rice(quantity1,itemNo2);                
                   
                  
                          MainTotal=MainTotal+MainTotal1;
           	    	
                      	  }
                          else
                          {
                          SetConsoleTextAttribute(h, 12);	
                	      cout<<"\n\n\t\t\t\tPlease Enter valid Amout!\n";
                	      SetConsoleTextAttribute(h,0xF);
                          goto quant;	
                          }
                           
                           }
                          else
                          {
                          SetConsoleTextAttribute(h, 12);
                	      cout<<"\n\n\t\tPlease Enter valid Amout!\n";
                	      SetConsoleTextAttribute(h,0xF);
                          goto quant;	
                          } 
                          
                         }
		                 else 
                           {
                           	 SetConsoleTextAttribute(h, 12);
                             cout<<"\n\n\t\tPlease Enter valid Amout!\n";
                             SetConsoleTextAttribute(h,0xF);
							 goto again2;
                         
                            }
                               order1:
                               SetConsoleTextAttribute(h, 14);
						       cout<<"\n\n\n\t\tYou Want order Again (Y/N) : "  ;     
                               cin>>letter;
                               SetConsoleTextAttribute(h,0xF);
                   
                               switch (letter)
                                 {
                                case 'Y' :goto again2; break;	
   	                            case 'y' :goto again2 ; break;	
   	                            case 'N' :goto goout ; break;
   	                            case 'n' :goto goout ; break; 
   	                            
   	                              default:cout<<"\n\n\t\t\tInvalid Input";goto order1;
   	                             
                                 } 
        	         }
   	                     SetConsoleTextAttribute(h, 12);
                         cout<<"\n\n\tPlease Enter valid Input!\n";;
                         SetConsoleTextAttribute(h,0xF);
                         goto again2;
                 }
        	     else 
        	      {
        	      SetConsoleTextAttribute(h, 12);
                  cout<<"\n\n\t\t\tPlease Enter valid Input!\n";
                  SetConsoleTextAttribute(h,0xF);
                  goto again2;

                  }
                     

                          goout: 
                          SetConsoleTextAttribute(h, 14);
     	                  cout<<"\n\n\t\t\tYou Want to Go Menu (Y/N) : ";
                          cin>>letter;
                          SetConsoleTextAttribute(h,0xF);
     	                  
     	    
                	      switch(letter)
              	           {
	   	                   case 'Y' :goto start; break;	
   	                       case 'y' :goto start ; break;	
   	                       case 'N' :goto cashCall ; break;
                           case 'n' :goto cashCall ; break; 
  	                         default:cout<<"\n\n\t\t\tInvalid Input !!!";goto goout;
	                       }
             
		          }
            
                
          
             else if (menu2==2)                                                                    //Kottu Menu
	   	               {
                          system("CLS");
                          SetConsoleTextAttribute(h,0xE);
                          cout<<"\n\t\t\t  ============================================================"<<endl;
                          SetConsoleTextAttribute(h, 10);
                   	      cout<<"\t\t\t\t\t\t___Kottu Menu___"<<endl;
                   	      SetConsoleTextAttribute(h,0xF);
						  cout<<"\n\t\t\t  ============================================================\n"<<endl;	        
		                  cout<<"\n\t\t\t\t\t\tFood\t\t\t  Prize\n";
       	                  cout<<"\n\t\t\t  ------------------------------------------------------------------"<<endl;
  		                  SetConsoleTextAttribute(h,0xF);  
					                                                                                    //for loop for Display Kottu Menu 
  	                   for(i=0;i<7;i++)
  	                    {
                         SetConsoleTextAttribute(h, 13);   	 
                         cout<<"\t\t\t\t\t"<<i+1<<". "<<kottu[i]<<"  :        RS. "<<priceK[i]<<endl;   
						  SetConsoleTextAttribute(h,0xF);    
  	                    }
  	                       cout<<"\n\t\t\t ------------------------------------------------------------------"<<endl;  
					   
					       again3:
       	                   cout<<"\n\n\t\t\tEnter Your Choice No \t   : ";
        	               cin>>itemN;
					          for (int i=0;i<itemN.length();i++) 
	        	               {
	        	                  if (isdigit(itemN[i]) == false) 
	         	                   {
		    	                    count2=1;
					  		
		     	                    break;
	      	                       }
	     	                     else
		                           {
	      	                      count2=0;
		                           }
		
	     	                    }
	    	                   if(count2==0)
                                {      
	                              stringstream con(itemN);
	                              con >> itemNo2;
        	
                     	            while(itemNo2>0)
        	                         {
     		                           if(itemNo2<foodamt)
  		                                 {
		                                      cout<<"\n\n\tYour Order => \t"<<itemNo2<<". "<<kottu[itemNo2-1]<<" \t   : RS. "<<priceK[itemNo2-1]<<endl;
	                                          quant1:
                                              cout<<"\n\t\t\tPleace enter Your quantity : ";
                                              cin>>quantity;
                                              for (int i=0;i<quantity.length();i++) 
	        	                                {
	        	                                  if (isdigit(quantity[i]) == false) 
	         	                                      {
		    	                                     count3=1;
					  		
		     	                                       break;
	      	                                           }
	     	                                           else
		                                               {
	      	                                         count3=0;
		                                               }
		
	     	                                     }
	    	                                        if(count3==0)
                                                      {
	                                                  stringstream con(quantity);
	                                                  con >> quantity1;
	                       
	                                                   if(quantity1>0)
	                                                     {
                                              
                                                           ofstream myFile("Bill.txt",ios::app);
		                                                   myFile<<"\n\n\t\t\t\t "<<kottu[itemNo2-1]<<"\t\t\t"<<quantity1<<"\t\t"<<priceK[itemNo2-1]<<endl;
		                                                   myFile.close();
                          
                          
                                                            MainTotal12=getTotal_kottu(quantity1,itemNo2);                
                 
                                                             MainTotal=MainTotal+MainTotal12;
                                                           
                                                         }
                                               
                                                        else
                                                         {
                                                         	SetConsoleTextAttribute(h, 12);
                	                                       cout<<"\n\n\t\t\tPlease Enter valid Amout!\n";
                	                                        SetConsoleTextAttribute(h,0xF);  
                                                           goto quant1;	
                                                         } 
           	    
                                                    }
		                                            else 
                                                     {
                                                     	SetConsoleTextAttribute(h, 12);
                                                        cout<<"\n\n\t\t\tPlease Enter valid Amout!\n";
                                                         SetConsoleTextAttribute(h,0xF);  
											            goto quant1;                               
         
                                                     }

                                     } 
                                     else
                                     {
                                     	SetConsoleTextAttribute(h, 12);
                                         cout<<"\n\n\t\t\tPlease Enter valid Input!\n";
                                          SetConsoleTextAttribute(h,0xF);  
                                         goto again3;
                                     }
                                     again4:
                                      SetConsoleTextAttribute(h, 14);
                                      cout<<"\n\n\t\t\tYou Want order Again (Y/N) : "  ;
                                      cin>>letter;
                                      SetConsoleTextAttribute(h,0xF);   
                                         switch (letter)
                                           {
                                            case 'Y' :goto again3; break;	
   	                                        case 'y' :goto again3 ; break;	
  	                                        case 'N' :goto goout ; break;
   	                                        case 'n' :goto goout ; break; 
   	                                        default:cout<<SetConsoleTextAttribute(h, 12);"\n\n\t\t\tInvalid Input";goto again4;break;
                                           } 
                  
                                   
	             
	   	                     }
                                 
	                                 goout1: 
	                                  SetConsoleTextAttribute(h, 14);
     	                             cout<<"\n\n\t\t\tYou Want to Go Menu (Y/N) : ";
     	                             cin>>letter;
     	                              SetConsoleTextAttribute(h,0xF);  
     	    
                	                 switch(letter)
              	                      {
	   	                              case 'Y' :goto start; break;	
   	                                  case 'y' :goto start ; break;	
   	                                  case 'N' :goto cashCall ; break;
   	                                  case 'n' :goto cashCall ; break; 
  	                                   default:cout<<"\n\n\t\t\tInvalid Input";goto goout1;break;
	                                  }
		              }
       
                  else
                  {
                  SetConsoleTextAttribute(h, 12);	
                  cout<<"\n\n\t\t\tPlease Enter valid Input!\n";
                   SetConsoleTextAttribute(h,0xF);  
                  goto again3;

                  }

          }   

              else
                  {
                  SetConsoleTextAttribute(h, 12);	
                  cout<<"\n\n\t\t\tPlease Enter valid Input!\n";
                   SetConsoleTextAttribute(h,0xF);  
                  goto again1;

                  }
  
              
            SetConsoleTextAttribute(h,0xE);
         
			cashCall:                                         //Bill create
           	system("CLS");
           	cout<<" \t\t\t\t ===========================================================\n"<<endl;
           	cout<<"\t\t\t\tYour Total :\t\t\t\t"<<MainTotal<<endl;
           	cout<<"\n\n\t\t\tEnter Your Cash : Rs . ";
           	cin>>cash;
           	if(MainTotal<cash)
           	{
	           	
	        
           	cout<<" \n\t\t\t\t ===========================================================\n"<<endl;
           	
           	while(cash>0)
           	{
	           	
               	cout<<" \t\t\t ------------------------------------------------------------------\n"<<endl;
   	    	    system("CLS");
    	    	cout<<" \t\t\t ------------------------------------------------------------------"<<endl;
    	    	SetConsoleTextAttribute(h, 10);
	    	    cout<<"\t\t\t\t\t\t__ VITO FOOD Place__ "<<endl<<endl;
	   	        cout<<"\t\t\t\t\t\t  ___Receipt___"<<endl;
	   	        cout<<"\t\t\t\t\t\t  15/b,kap.mw,kandy"<<endl;
	   	        SetConsoleTextAttribute(h,0xF);
   		        cout<<"\n \t\t\t ------------------------------------------------------------------"<<endl;
   		    
   		        time_t tt;
	            struct tm*ti;
         	    time(&tt);
        	    ti=localtime(&tt); 
        	
    		   cout<<"\t\t\tReceipt_No:- 4576\t\t\t"<<asctime(ti)<<endl;
	           cout<<"\n\t\t\t\t\t\t\t\t qnt\t\tRs."<<endl;
	           ifstream myFile("Bill.txt");
	              if (myFile.is_open())
	               {
        		     while(getline(myFile,line))
        		      {
		        	  cout<<line<<endl;
		              }
		              myFile.close();
        	      }
        		     if(MainTotal>0)
        		       {
                         cout<<" \n\n\n\t\t\t------------------------------------------------------------------"<<endl;
	                     cout<<"\t\t\tAmout Total :\t\t\t\t"<<MainTotal<<endl;
	                     cout<<" \t\t\t ------------------------------------------------------------------"<<endl;
	                     cout<<"\t\t\tCASH :\t\t\t\t\t"<<cash<<endl;
	                     cout<<" \t\t\t=================================================================="<<endl;
	                     cout<<"\t\t\tCHANGE :\t\t\t\t"<<getChange(MainTotal,cash)<<endl;
	                     cout<<" \t\t\t==================================================================\n"<<endl;
	                     cout<<"\n\n\t\t\t\t\t\tTel.:+09499999"<<endl;
                         cout<<"\t\t\t\t\t\tFax.:+09488889"<<endl;
	                     cout<<"\t\t\t\t\t  E-mail:Vitofd@gmail.com"<<endl<<endl;
	                     std::ofstream ofs ("Bill.txt", std::ios::out | std::ios::trunc); // clear contents
				         ofs.close ();
				
	                     cout<<"\n\n\t\t\t\tYou Want to Order Again (Y/N) : " ;
	                     cin>>letter;
	                      SetConsoleTextAttribute(h, 13);
	                       switch(letter)
                             {
                            	
           	                case 'Y' :goto start; break;	
        	                case 'y' :goto start ; break;
				            case 'N' :cout<<"\n\n\t\tThank You!!! Come Again...\n\n\n\n"; break;
                            case 'n' :cout<<"\n\n\t\tThank You!!! Come Again...\n\n\n\n"; break;	
    	                     default: cout<<"\n\n\t\tThank You. Come Again another Day!!!";break;
				            
                             }
				
	        
	                           SetConsoleTextAttribute(h,0xF);
	                           exit(0);
	         
	                             ofstream myFile("Bill.txt");
      	                         if(myFile.is_open())
                	              {
	         	                 myFile.close();
                	               }
              	                   else 
              	                    {
		
              	                    }
          
	        
               	}
      		      else
      		       {
		      	
		           }
			   
			}
                SetConsoleTextAttribute(h, 12);
                cout<<"\t\t\tInvalid input!!! \n\n\t\t\tPlease Enter Valid Cash"<<endl;
                 SetConsoleTextAttribute(h,0xF);  
				goto cashCall;
           	}
           	else
           	{
           		 SetConsoleTextAttribute(h, 12);
	           	cout<<"The amout you pay is NOT ENOUGH for the Selected items !!!";
	           	SetConsoleTextAttribute(h,0xF); 
	           	goto cashCall;
	           }
           }
		   else
		   {
               
				goto again1;
               

		   }
        
     }   
     
     
double getTotal_rice(int quantity1,int itemNo2)              //to get total
  {
   float priceR[7]={550,450,750,850,450,450,650};
   
   float Tot=0;
   Tot=quantity1*priceR[itemNo2-1];

  	return Tot;

  }	
double getTotal_kottu(int quantity1,int itemNo2) 
  {
 float priceK[7]={400,300,550,800,600,250,700};
 
  float Tot=0;
   Tot=quantity1*priceK[itemNo2-1];

  	return Tot;
  }        
double getChange(float MainTotal,float cash)
{
	return cash-MainTotal;
}     

       	    
          