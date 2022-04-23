#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "PatientInformation.h"
#include "DailyCheck.h"
#include "Patient.h"
#include "Infected.h"
#include "Workers.h"
#include "Doctor.h"
#include "QuaratineRoom.h"
#include "EmergancyRoom.h"
#include "Hospital.h"
#include "HospitalInformation.h"
#include "LogInSystem.h"
#include <windows.h>
#include <iomanip>
using namespace std;


int main()
{
    string signinID;
    int number_of_Patients;
    int number_of_Doctors;
    int number_of_Nurses;
    bool check_patient_data=false;
    bool check_doctors_data=false;
     bool check_nurses_data=false;
    bool patientFile_was_empty=false;
    bool doctorsFile_was_empty=false;
    bool nursesFile_was_empty=false;
    bool HopitalFile_was_empty =false;
     int counter_patients=0;
    int counter_doctors=0;
    int counter_nurses = 0 ; 
    
    Hospital HospitalInfo;
    
    fstream P_read_write("D:\\FINALPROJECT\\DataBases\\Patients.txt", ios::in | ios::out );
    fstream D_read_write("D:\\FINALPROJECT\\DataBases\\Doctors.txt", ios::in | ios::out );
    fstream N_read_write("D:\\FINALPROJECT\\DataBases\\Nurses.txt", ios::in | ios::out );
    fstream HGI_read_write ("D:\\FINALPROJECT\\DataBases\\HospitalGeneralInformation.txt", ios::in | ios::out );
   // fstream QRoom_read_write ("D:\\FINALPROJECT\\DataBases\\QuaratineRoom.txt", ios::in | ios::out |ios::binary | ios::app);
    
    
    if (!P_read_write)
    {
        cout <<"These is no Database for patients Information"<<endl;
        exit(0);
    }
    
    if (!D_read_write)
    {
        cout <<"These is no Database for Doctors Information"<<endl;
        exit(0);
    }

    if (!N_read_write)
    {
        cout <<"These is no Database for Nurses Information"<<endl;
        exit(0);
    }

    if (!HGI_read_write)
          {
        cout <<"These is no Database for Hospital Information"<<endl;
        exit(0);
        }


//to check from the file for patients is it open or not if not will jump to setup_part else will read from the file
//the purpose from the below codes is to let the user to set the size of the objects arrays
       if ( HGI_read_write.peek() == std::ifstream::traits_type::eof() )
   {cout <<"There are no Data for the Hospital Inforamtion you need to setup the program..."<<endl;
        HopitalFile_was_empty=true;
        
    }
   
    
    
    
      if ( P_read_write.peek() == std::ifstream::traits_type::eof() )
   {cout <<"There are no Data for the Patients you need to setup the program..."<<endl;
        check_patient_data=true;
        patientFile_was_empty=true;
        goto setup_part;
    }
     
     
       
       
  
   check_read_DoctorsFile: 

 //to check from the file for doctors is it open or not if not will jump to setup_part else will read from the file
   
    if ( D_read_write.peek() == std::ifstream::traits_type::eof() )
   {cout <<"There are no Data for the Doctors you need to setup the program..."<<endl;
        check_doctors_data=true;
        doctorsFile_was_empty=true;
        goto setup_part;
    }


 
      
    
    
    

//to check from the file for nurses is it open or not if not will jump to setup_part else will read from the file
check_read_NursesFile: 

   if ( N_read_write.peek() == std::ifstream::traits_type::eof() )
   {cout <<"There are no Data for the Nurses you need to setup the program..."<<endl;
        check_nurses_data=true;
        nursesFile_was_empty=true;
        goto setup_part;
    }


 
     
    

    
     
     
    setup_part:
    {
        if (check_patient_data==true)
        {
            cout <<"<<<<YOU ARE CURRENTLY SETTING UP THE SYSTEM FOR THE FIRST TIME>>>>"<<endl<<endl;
            cout <<"You will create object for Infected Class"<<endl;
            cout <<"Please Insert the number of Patients [1-140] :: ";
            cin >>number_of_Patients;
            
            //these are some limit conditions for the system
        if (number_of_Patients > 140)
            {
        cout <<"You Have excceded the patient limit number ...\nThe system will fix it atuomatical and set it to 140"<<endl;
        number_of_Patients=140;
    
            }
            
         //  P_read_write.clear();
        // P_read_write<<number_of_Patients<<endl;
            //the reason why we change the value here is just to stop the loop
            check_patient_data=false;
                //sleep statment will delay the next statment for 1.5 s
                Sleep(1500);
                system ("CLS");
           goto check_read_DoctorsFile;

        }
        
         if (check_doctors_data==true)
        {
            cout <<"<<<<YOU ARE CURRENTLY SETTING UP THE SYSTEM FOR THE FIRST TIME>>>>"<<endl<<endl;
            cout <<"You will create object for Doctor Class"<<endl;
            cout <<"Please Insert the number of doctors [1-20] :: ";
             cin >>number_of_Doctors;
             if (number_of_Doctors>20)
                {
                cout <<"You Have excceded the Doctors limit number ...\nThe system will fix it atuomatical and set it to 20"<<endl;
                number_of_Doctors=20;
          
                }
             
            D_read_write.clear();
           //  D_read_write<<number_of_Doctors<<endl;
            //the reason why we change the value here is just to stop the loop
            check_doctors_data=false;
            //sleep statment will delay the next statment for 1.5 s
            Sleep(1500);
             system ("CLS");
          goto check_read_NursesFile;
           
            
        }
        
        if (check_nurses_data==true)
        {
            cout <<"<<<<YOU ARE CURRENTLY SETTING UP THE SYSTEM FOR THE FIRST TIME>>>>"<<endl<<endl;
            cout <<"You will create object for Nurses Class"<<endl;
            cout <<"Please Insert the number of Nurses [1-20] :: ";
             cin >>number_of_Nurses;
             
             if (number_of_Nurses>20)
                {
              cout <<"You Have excceded the Nurses limit number ...\nThe system will fix it atuomatical and set it to 20"<<endl;
                number_of_Nurses=20;
                
                }
            N_read_write.clear();
            // N_read_write<<number_of_Nurses<<endl;
            //the reason why we change the value here is just to stop the loop
            check_nurses_data=false;
            //sleep statment will delay the next statment for 1.5 s
            Sleep(1500);
            system ("CLS");
            
        }
        
    }
    
    //this part is to read the data from the files if the file is not empty
    if (patientFile_was_empty==false)
    {
       // P_read_write.clear();
       // P_read_write.seekg(0,ios::beg);
           P_read_write>>number_of_Patients;  
            P_read_write>>counter_patients;   
           // cout<<P_read_write.tellg()<<endl;
           
    }
    
    //creating infected objects based on data inserted by the user if the patient database was empty
    //if it wasn't the object will be created based on the data in patient database and it will read the data from there
    Infected infected_Patient[number_of_Patients];
    
       if (patientFile_was_empty==false)
       {      
     //  while (!P_read_write.eof())
//{
                
                for (int f =0 ; f <counter_patients; f++)
                {
                    string name1,phonenumber,addressp, currentroom,conditonpa,idpatient;
                    getline(P_read_write,name1,',');
                     getline(P_read_write,phonenumber,',');
                     getline(P_read_write,addressp,',');
                     
                     getline(P_read_write,currentroom,',');
                       getline(P_read_write,conditonpa,',');
                        getline(P_read_write,idpatient);
                    infected_Patient[f].setAllPatientInfoByPassing (name1, phonenumber,addressp );
                    infected_Patient[f].setCurrentRoom(currentroom);
                     infected_Patient[f].setPatientConditon(conditonpa);
                    infected_Patient[f].setPatientID(idpatient);
                
                
                for (int h=0;h<7;h++)
                {
                    string symtoms;
                    if (h==6)
                    {
                        getline(P_read_write,symtoms);
                    infected_Patient[f].SetSymptoms(h,symtoms);
                    break;
                    }
                    getline(P_read_write,symtoms,',');
                    infected_Patient[f].SetSymptoms(h,symtoms);
                    
                }
                
                for (int s=0;s<3;s++)
                {
                    string store1,store2,store3,store4,store5,store6,store7;
                    getline(P_read_write,store1,',');
                    getline(P_read_write,store2,',');
                    getline(P_read_write,store3,',');
                    getline(P_read_write,store4,',');
                    getline(P_read_write,store5,',');
                    getline(P_read_write,store6,',');
                    getline(P_read_write,store7);
                    infected_Patient[f].setDataFordailycheck(s,store3,store4,store5,store6,store7,store1 , store2);
                    
                }
                
                }
           //}
           
            
       }
      
        
       
      //this part is to read the data from the files if the file is not empty  
     if (doctorsFile_was_empty==false)
    {
          D_read_write >>number_of_Doctors;
         D_read_write>>counter_doctors; 
       //  cout<<D_read_write.tellg()<<endl;
    }   
        //creating doctor objects based on data inserted by the user if the doctor database was empty
    //if it wasn't the object will be created based on the data in doctors database and it will read the data from there
    Doctor doctors[number_of_Doctors];
    

     if (doctorsFile_was_empty==false)
     {
        //  while (!D_read_write.eof())
       //  {  
            for (int k=0; k < counter_doctors; k++)
            {
                string store_1,store_2,store_3,store_4,store_5;
                int yearofexper;
                getline(D_read_write,store_1,',');
             //   cout <<store_1<<endl;
                
                getline(D_read_write,store_2,',');
               // cout <<store_2<<endl;
                getline(D_read_write,store_3,',');
//cout <<store_3<<endl;
                getline(D_read_write,store_4,',');
              //  cout <<store_4<<endl;
                getline(D_read_write,store_5,',');
              //  cout <<store_5<<endl;
                D_read_write>>yearofexper;
                
                doctors[k].setWorkerName(store_1);
                doctors[k].setWorkerID(store_2);
                doctors[k].setWorkerPhoneNumber(store_3);
                doctors[k].setSpecialization(store_4);
                doctors[k].setWorkingRoom(store_5);
                doctors[k].setYearsOfExperience(yearofexper);
                

                
            
            for (int j =0 ; j < 7 ; j++)
            {
                
                string storeID;
               D_read_write>>storeID;
           
                 if (storeID!="Null")
                {
                    for (int x=0; x < counter_patients;x++)
                    {
                        if (storeID==infected_Patient[x].getPatientID())
                        {
                            doctors[k].matchclass(&infected_Patient[x]);
                        
                            break;
                        }
                        
                    }
                    
                }
                
            }
        
        }
       // break;
        //}
     }
      //doctors[0].matchclass(&infected_Patient[0]);
     
    //this part is to read the data from the files if the file is not empty  
    if (nursesFile_was_empty==false)
    {
        
       N_read_write >>number_of_Nurses;
        N_read_write>>counter_nurses;
    }  
    
        //creating doctor objects based on data inserted by the user if the doctor database was empty
    //if it wasn't the object will be created based on the data in doctors database and it will read the data from there
    
          Workers nurses[number_of_Nurses];
           if (nursesFile_was_empty==false)
           {
         //   while (!N_read_write.eof())
       //  {
               for (int k=0; k < counter_nurses; k++)
            {
                string store_1,store_2,store_3,store_4;
                int yearofexper;
                getline(N_read_write,store_1,',');
           //     cout <<store_1<<endl;
                getline(N_read_write,store_2,',');
             //   cout <<store_2<<endl;
                getline(N_read_write,store_3,',');
              //  cout <<store_3<<endl;
                getline(N_read_write,store_4,',');
              //  cout <<store_4<<endl;
                N_read_write>>yearofexper;
                
                nurses[k].setWorkerName(store_1);
                nurses[k].setWorkerID(store_2);
                nurses[k].setWorkerPhoneNumber(store_3);
                nurses[k].setWorkingRoom(store_4);
                nurses[k].setYearsOfExperience(yearofexper);
            
            
            for (int j =0 ; j < 7 ; j++)
            {
                
                string storeID;
              N_read_write>>storeID;
              
                 if (storeID!="Null")
                {
                    for (int x=0; x < counter_patients;x++)
                    {
                        if (storeID==infected_Patient[x].getPatientID())
                        {
                            nurses[k].matchclass(&infected_Patient[x]);
                            break;
                        }
                        
                    }
                    
                }
                
            }
        
        
        }
        
        
   //   }// break; 
        }
        
        
                        for (int x = 0 ; x <counter_doctors ; x++)
                                {HospitalInfo.matchDr(&doctors[x]);}
                                
                            for (int y=0 ; y < counter_nurses ; y ++)
                                {HospitalInfo.matchNurses(&nurses[y]);}
                                
                            for (int j=0 ; j <  counter_patients; j++)
                                {HospitalInfo.matchIfectedwithRooms(&infected_Patient[j]);}
                            /*for (int j=0 ; j <  counter_patients; j++)
                                {  
                                    HospitalInfo.QRsetid(infected_Patient[j].getPatientID());
                                 
                                }*/
           system("CLS");
           
    if (HopitalFile_was_empty==false)
    {
        //this part to read and store the hospital infomration
        
        string store1,store2,store3;
        
        getline( HGI_read_write,store1,',');
        getline( HGI_read_write,store2,',');
        getline( HGI_read_write,store3);
        
        HospitalInfo.sethopitallocation(store1);
        HospitalInfo.sethospitalname(store2);
        HospitalInfo.sethopitalcontactnum(store3);
        
        for (int i=0 ; i <counter_patients; i ++)
        {
              string store1_id;
                string store_start;
                string store_end;
               getline(HGI_read_write,store1_id,',');
               getline(HGI_read_write,store_start,',');
               getline(HGI_read_write,store_end);
               
               HospitalInfo.QRSetRoomResidentsbyPassing(i,store_start,store_end,store1_id);
               
            
        }
        
        //this part to read and store the data in the quaraitne room
      //  while(!QRoom_read_write.eof())    
        //{
            
       // }
            
    }
    
    
                           
                                
/*
     if (HopitalFile_was_empty==false)
       {
          
           
           
           for (int c=0 ; c < counter_patients ; c++)
           {
               string store1_id;
                string store_start;
                string store_end;
               getline(QRoom_read_write,store1_id,',');
               getline(QRoom_read_write,store_start,',');
               getline(QRoom_read_write,store_end);
               
               HospitalInfo.QRSetRoomResidentsbyPassing(c,store_start,store_end,store1_id);
               
        }
           
        }
    */
    
     /*
    * these operation is to pass the data into the emergancy room and quaratine room
    * */
                        
                 
    /*
     * the conditons here is to compare the number of patients in the hospital 
     * and the number of nurses and doctors and how much they can handle
     * some times the number of patients can excced the number that can be handled
     * from the doctors and nurses so the patients inforamtion will be onll modified by the admin 
     * and it will be stored in the file , the admin can ignor the overloaded patients
     * */
    
    if ((number_of_Nurses*7)<number_of_Patients)
    {
        cout <<"Note :: there will be ["<<(number_of_Patients-(number_of_Nurses*7))<<"] of patients"<<endl;
        cout <<"That you will not be able to match them to Nurses..."<<endl;
        
    }
    
     if ((number_of_Doctors*7)<number_of_Patients)
    {
        cout <<"Note :: there will be ["<<(number_of_Patients-(number_of_Doctors*7))<<"] of patients"<<endl;
        cout <<"That you will not be able to match them to Doctors..."<<endl;
        
    }

    
    
    if (patientFile_was_empty==true)
    {
        cout <<"Note:: Since the Patient's Database was empty you have to set up the patient's information"<<endl;
        
    }
    
     if (doctorsFile_was_empty==true)
    {
        cout <<"Note:: Since the Doctor's Database was empty you have to set up the Doctors's information"<<endl;
    }
    
      if (nursesFile_was_empty==true)
    {
        cout <<"Note:: Since the Nurses's Database was empty you have to set up the Nurses's information"<<endl;
    }
    
    
    
    /*
     * defining the login system and matching the classes
     * 
     *this part is for the log in system
     * it will check from the ID
     * */
     
     LogInSystem LogIn;
     
     for (int i = 0 ; i <counter_patients ; i++ )
           { LogIn.MatchClasses(&infected_Patient[i]);}
           
     for (int i = 0 ; i <counter_doctors ; i++ )
           { LogIn.MatchClasses(&doctors[i]);}
    
    for (int i = 0 ; i < counter_nurses ; i++ )
           { LogIn.MatchClasses(&nurses[i]);}
           
           
           
     bool checkfirstLetter_Admin =false;
     bool checkfirstLetter_Patient=false;
     bool checkfirstLetter_Nurse=false;
     bool checkfirstLetter_Doctor=false;
    bool resetting_the_system = false ;
    
    
   

    
    
   if ((patientFile_was_empty==true)||(doctorsFile_was_empty==true)||(nursesFile_was_empty==true)||(HopitalFile_was_empty==true))
    {
        signinID="Admin";
      cout <<" <<<< You have to set up the program from the begining becuase one of Your file is empty>>>>"<<endl;
      checkfirstLetter_Admin=true;
      resetting_the_system =true;
      if (patientFile_was_empty==true)
        {cout <<"**** Your Patinet File is Empty ****"<<endl;}
     if (doctorsFile_was_empty==true)
        {cout <<"**** Your Doctor File is Empty ****"<<endl;}  
     if (nursesFile_was_empty==true)
        {cout <<"**** Your Nurse File is Empty ****"<<endl;}  
    if (HopitalFile_was_empty==true)
        {cout <<"**** Your Hospital Information File is Empty ****"<<endl;}  
                
        
        /*if the patient file was empty you have to set up the program from the begining 
         * because you have to re-match the doctors and rooms with the new patients
         * otherwise there will be alot of errors.
         * if the doctor files was empty or the nurses file you have to re-match the relationships with the patients againg
         * so in the end if any of the file was empty you have to re-set the entire system
         * */
        
        cout <<"----------------------------------------------------------------------\n\n"<<endl;
        
        goto Admin_controll_setting;
    }
    
    else 
    {
        cout <<"The Screen Will be Cleared after 5s ..."<<endl;
       // Sleep(5000);
    //  system("CLS");
      
      logingpage:
        cout <<"Please Enter Your ID :: ";
            cin >> signinID;
        if (LogIn.checkID(signinID)==true)
        {
            
            if (signinID.substr(0,1)=="A")
            {
                checkfirstLetter_Admin=true;
                goto admin_part_not_setting_by_id;
            }
            else if (signinID.substr(0,1)=="N")
            {
                checkfirstLetter_Nurse =true;
                goto Nurse_controll;
            }
            else if (signinID.substr(0,1)=="D")
            {
                
                checkfirstLetter_Doctor=true;
                goto Doctor_controll;
            }
            else if (signinID.substr(0,1)=="P")
            {
                
                checkfirstLetter_Patient=true ;
                goto Patient_controll;
                }
            
        }
        
        else 
        {
            char continue_y;
            cout <<"There is no matching ID...."<<endl;
            cout <<"To try Again please Enter (Y) ::";
            cin >>continue_y;
            if ((continue_y=='y')||(continue_y=='Y'))
                {goto logingpage;}
            else 
            {cout << "You choose to exit !!!"<<endl;
                goto write_data;
            }
        }
    }
    
    /*
     * this part is to setup the program
     * */
     

    
    
             
    Admin_controll_setting:
        //this part is for setting the system objcet by object
        if ((resetting_the_system==true)&&(checkfirstLetter_Admin==true))
        
            {
               
            main_menu:
            
                
                int input_number=434;
               
                for (;input_number!=5;)
                {
                     cout <<"<<<You are going to setup the system>>>"<<endl;
                    cout << "Please choose one of the below lists to start with it"<<endl;
                    cout <<"1- The Patients Data"<<endl;
                    cout <<"2- The doctors Data"<<endl;
                    cout <<"3- The Nurses Data"<<endl;
                    cout <<"4- The Hospital Data"<<endl;
                    cout <<"5- Exit from the System"<<endl;
               
                     cout <<"Enter the Nubmer ::";
                        cin >> input_number;
                         cin.ignore();
                         
                   //begining of patient data list
                    if (input_number==1)
                    {
                        Sleep(1000);
                        system("CLS");
                        cout << "You Have ["<<number_of_Patients<<"] Patients that you need to set..."<<endl;
                        
                         
                        for (int i=0  ; i < number_of_Patients; i ++)
                        {
                            int inside_loop_controll = 4343;
                            cout << "Patient Number ["<<i+1<<"] "<<endl;
                           
                            cout <<" <<< Paitent Menu >>>"<<endl;
                            cout <<"1- Insert Personal Inforamtion "<<endl;
                            cout <<"2- Insert The Patient Room  "<<endl;
                            cout <<"3- Insert The Patient's ID "<<endl;
                       //     cout <<"4- Insert People in Contact with Patient "<<endl;
                             cout <<"4- Back To Main Menu "<<endl;
                            cout <<"5- Go to Next Paitnet "<<endl;
                           counter_patients++;
                            
                            for (;inside_loop_controll!=5;)
                            {
                                string store_strings;
                                 cout << "Choose a Number from Paitent Menu ::";
                                    cin >>inside_loop_controll;
                                 cin.ignore();
                                if (inside_loop_controll==1)
                                {
                                    infected_Patient[i].EditPatientInfo();
                                }
                                else if (inside_loop_controll==2)
                                {
                                    
                                cout <<"Enter the Room  [QuaratineRoom,EmergancyRoom] :: "; 
                                cin >> store_strings;
                                infected_Patient[i].setCurrentRoom(store_strings);
                                 }
                                else if (inside_loop_controll==3)
                                {
                                      cout <<"Enter the ID (P*****) ::";
                                        cin >>store_strings;
                                    infected_Patient[i].setPatientID(store_strings);
                                }
                               /* else if (inside_loop_controll==4)
                                {
                                    int num1=0;
                                    cout <<"How many People the Patient was in Contact with (x < 6) ::";
                                    cin >>num1;
                                    
                                    for (int j = 0 ; j < num1 ; j++)
                                    {
                                        string store_strings2;
                                        cout <<"Enter Name ["<<j+1<<"] ::";
                                        getline(cin, store_strings2);
                                        infected_Patient[i].setPeopleInContact(j,store_strings2);
                                
                                    }
                                        
                                    
                                }
                                */
                                else if (inside_loop_controll==4)
                                {
                                    cout<<"Patient Counter will set to 0...."<<endl;
                                    cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    counter_patients=0;
                                    goto main_menu;
                                }
                                
                                else 
                                {
                                    cout <<"You Choose to go to next Patient .."<<endl;
                                    cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    break;
                                }
  
                            }
                            
                            
                            
                        }
                        
                        cout <<"You have setup the data for all patients..."<<endl;
                            Sleep(2000);
                            system("CLS");
                } //end of patient data list 
               
                   //begining of Doctors list
                    else if  (input_number==2)
                    {
                        
                         Sleep(1000);
                        system("CLS");
                        cout << "You Have ["<<number_of_Doctors<<"] Doctors that you need to set..."<<endl;
                        
                         
                        for (int i=0  ; i < number_of_Doctors; i ++)
                        {
                            int inside_loop_controll_2 = 4343;
                            cout << "Doctor Number ["<<i+1<<"] "<<endl;
                            cout <<"Doctor Menu"<<endl;
                            cout <<"1- Insert Doctor's Name"<<endl;
                            cout <<"2- Insert Doctor's PhoneNumber"<<endl;
                            cout <<"3- Insert Doctor's  Experiences Years "<<endl;
                            cout <<"4- Insert Doctor's Specailization"<<endl;
                            cout <<"5- Insert Doctor's Working Room"<<endl;
                            cout <<"6- Insert Doctor's ID"<<endl;
                            cout <<"7- Connect Doctor's With their Patients (needed) "<<endl;
                            cout <<"8- Back to Main Menu"<<endl;
                            cout <<"9- Go to Next Doctor"<<endl;
                           
                           counter_doctors++;
                            
                            for (;inside_loop_controll_2!=9;)
                            {
                                outsideloop232:
                                string store_strings_3;
                                 cout << "Choose a Number from Doctor Menu ::";
                                    cin >>inside_loop_controll_2;
                                 cin.ignore();
                                 
                                 if (inside_loop_controll_2 ==1 )
                                 {
                                      cout <<"Enter the Docter's Name :: ";
                                        getline(cin,store_strings_3);
                                        doctors[i].setWorkerName(store_strings_3);
                                }
                                    
                                else if (inside_loop_controll_2==2)
                                {
                                     cout <<"Enter the Docter's PhoneNumber (*No spaces) :: ";
                                                cin >>store_strings_3;
                                                doctors[i].setWorkerPhoneNumber(store_strings_3);
                                }
                                
                                  else if (inside_loop_controll_2==3)
                                  {  
                                          cout <<"Enter the Docter's Experience Years (x>0) :: ";
                                                int year1;
                                                cin >>year1;
                                                doctors[i].setYearsOfExperience(year1);
                                    }
                                else if (inside_loop_controll_2==4)
                                {           
                                          cout <<"Enter the Docter's Specialization :: ";
                                        getline(cin,store_strings_3);
                                        doctors[i].setSpecialization(store_strings_3);
                                }
                                else if (inside_loop_controll_2==5)
                                {
                                      cout <<"Enter the Docter's Working Room [QuaratineRoom,EmergancyRoom] (*no spaces) ::";
                                        cin >> store_strings_3;
                                        doctors[i].setWorkingRoom(store_strings_3);
                                    
                                }
                                else if (inside_loop_controll_2==6)
                                {
                                    cout <<"Enter the Doctor's ID (D*****)::";
                                    cin >> store_strings_3;
                                    doctors[i].setWorkerID(store_strings_3);
                                    
                                }
                                
                                else if (inside_loop_controll_2==7)
                                {
                                    
                                     cout <<"You have to conncet the Doctors with thier patients..."<<endl;
                                    cout<<"Enter how many patients ther doctor responsible of (x < 8) ::";
                                            int responsible1;
                                            cin >>responsible1;
            
                                    for (int k = 0 ; k < responsible1;k++)
                                    {
                                        string idd;
                                        cout << "Please insert the ID for patient ["<<k+1<<"] :: ";
                                        cin >>idd;
                                        bool matching1 = false;
                                        
                                            for (int w=0 ; w <number_of_Doctors ; w++)
                                        {
                                            if (doctors[w].CheckPateintID(idd)==true)
                                            {
                                                cout <<"The Patient is aleady undersupervision with another Doctor..."<<endl;
                                                goto outsideloop232;
                                            }
                                        }
                                        
                                            for (int j = 0; j < number_of_Patients ; j ++)
                                                {
                
                                                    if (idd==infected_Patient[j].getPatientID())
                                                        {
                                                                if (doctors[i].getWorkingRoom()==infected_Patient[j].getCurrentRoom())
                                                                    {
                                                                        doctors[i].matchclass(&infected_Patient[j]);
                                                                        matching1=true;
                                                                        break;
                                                                        }
                                                                else
                                                                {
                                                                cout <<"The Patient is in a different room from the the doctor"<<endl;
                                                                break;
                                                                }
                                                        }
                                                    else
                                                        {
                                                    matching1=false;
                                                        }
                                                }
                
                                            if (matching1==false)
                                            {cout << "cannot find the Patient's ID"<<endl;}
                                            else 
                                            {
                                            cout <<"The Patient is Connected Now with the Doctor"<<endl;
                                            }
                
                                            }
                                    
                                }//end of if condtion  6 for the list

                                else if (inside_loop_controll_2==8)
                                {
                                    cout<<"Doctor Counter will set to 0...."<<endl;
                                     cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    counter_doctors=0;
                                    goto main_menu;
                                }
                                 else 
                                {
                                    cout <<"You Choose to go to next Doctor .."<<endl;
                                    cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    break;
                                }
   
                            }
                            
                          
                        }
                        
                          cout <<"You have setup the data for all doctors..."<<endl;
                            Sleep(2000);
                            system("CLS");
                    }//end of Doctors list
                    
                    //begining of Nureses List
                     else if  (input_number==3)
                    {
                        
                        Sleep(1000);
                        system("CLS");
                        cout << "You Have ["<<number_of_Nurses<<"] Nurses that you need to set..."<<endl;
                        
                         
                        for (int i=0  ; i < number_of_Nurses; i ++)
                        {
                            int inside_loop_controll_3 = 4343;
                            cout << "Nurse Number ["<<i+1<<"] "<<endl;
                            cout <<"Nurse Menu"<<endl;
                            cout <<"1- Insert Nurse's Name"<<endl;
                            cout <<"2- Insert Nurse's PhoneNumber"<<endl;
                            cout <<"3- Insert Nurse's  Experiences Years "<<endl;
                            cout <<"4- Insert Nurse's Working Room"<<endl;
                            cout <<"5- Insert Nurse's ID"<<endl;
                            cout <<"6- Connect Nurse's With their Patients (needed) "<<endl;
                            cout <<"7- Back to Main Menu"<<endl;
                            cout <<"8- Go to Next Nurse"<<endl;
                           
                           counter_nurses++;
                            
                            for (;inside_loop_controll_3!=8;)
                            {
                                outsideloop:
                                string store_strings_3;
                                 cout << "Choose a Number from Nurse Menu ::";
                                    cin >>inside_loop_controll_3;
                                 cin.ignore();
                                 
                                 if (inside_loop_controll_3 ==1 )
                                 {
                                      cout <<"Enter the Nurse's Name :: ";
                                        getline(cin,store_strings_3);
                                        nurses[i].setWorkerName(store_strings_3);
                                }
                                    
                                else if (inside_loop_controll_3==2)
                                {
                                     cout <<"Enter the Nurse's PhoneNumber (*No spaces) :: ";
                                                cin >>store_strings_3;
                                                nurses[i].setWorkerPhoneNumber(store_strings_3);
                                }
                                
                                  else if (inside_loop_controll_3==3)
                                  {  
                                          cout <<"Enter the Nurse's Experience Years (x>0) :: ";
                                                int year1;
                                                cin >>year1;
                                                nurses[i].setYearsOfExperience(year1);
                                    }

                                else if (inside_loop_controll_3==4)
                                {
                                      cout <<"Enter the Nurse's Working Room [QuaratineRoom,EmergancyRoom] (*no spaces) ::";
                                        cin >> store_strings_3;
                                        nurses[i].setWorkingRoom(store_strings_3);
                                    
                                }
                                else if (inside_loop_controll_3==5)
                                {
                                    cout <<"Enter the Nurse's ID (N*****)::";
                                    cin >> store_strings_3;
                                    nurses[i].setWorkerID(store_strings_3);
                                    
                                }
                                
                                else if (inside_loop_controll_3==6)
                                {
                                    
                                     cout <<"You have to conncet the Nurse with thier patients..."<<endl;
                                    cout<<"Enter how many patients ther Nurse responsible of (x < 8) ::";
                                            int responsible1;
                                            cin >>responsible1;
            
                                    for (int k = 0 ; k < responsible1;k++)
                                    {
                                        string idd;
                                        cout << "Please insert the ID for patient ["<<k+1<<"] :: ";
                                        cin >>idd;
                                        bool matching1 = false;
                                        
                                        for (int w=0 ; w <number_of_Nurses ; w++)
                                        {
                                            if (nurses[w].CheckPateintID(idd)==true)
                                            {
                                                cout <<"The Patient is aleady undersupervision with another Nurse..."<<endl;
                                                goto outsideloop;
                                                }
                                        }
                                            for (int j = 0; j < number_of_Patients ; j ++)
                                                {
                
                                                    if (idd==infected_Patient[j].getPatientID())
                                                        {
                                                                if (nurses[i].getWorkingRoom()==infected_Patient[j].getCurrentRoom())
                                                                    {
                                                                        nurses[i].matchclass(&infected_Patient[j]);
                                                                        matching1=true;
                                                                        break;
                                                                        }
                                                                else
                                                                {
                                                                cout <<"The Patient is in a different room from the the Nurse"<<endl;
                                                                break;
                                                                }
                                                        }
                                                    else
                                                        {
                                                    matching1=false;
                                                        }
                                                }
                
                                            if (matching1==false)
                                            {cout << "cannot find the Patient's ID"<<endl;}
                                            else 
                                            {
                                            cout <<"The Patient is Connected Now with the Nurse"<<endl;
                                            }
                
                                        }
                                    
                                }//end of if condtion 6 for the list

                                else if (inside_loop_controll_3==7)
                                {
                                    cout <<"Nurses counter will set to 0 ...."<<endl;
                                     cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    counter_nurses=0;
                                    goto main_menu;
                                }
                                 else 
                                {
                                    cout <<"You Choose to go to next Nurse .."<<endl;
                                    cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    break;
                                }
   
                            }
                            
                           
                            
                        }
                          cout <<"You have setup the data for all Nurses..."<<endl;
                            Sleep(2000);
                            system("CLS");
                        
                    } //Ending of Nureses List
                
                     else if  (input_number==4)//start list for the hospital
                     {
                          
                        Sleep(1000);
                        system("CLS");
                        cout << "You Have to Set up the Hospital Inforamiton"<<endl;
                        
                            cout <<"1- Hospital Name"<<endl;
                            cout <<"2- Hospital Location"<<endl;
                            cout <<"3- Hospital Contact Number"<<endl;
                            cout <<"4- Go to the Main Menu"<<endl;
                            int inside_loop_controll_4 = 4343;
                         
                       
                            for (;inside_loop_controll_4!=4;)
                            {
                                string store_strings_4;
                                 cout << "Choose a Number from Hospital Menu ::";
                                    cin >>inside_loop_controll_4;
                                 cin.ignore();
                                 
                                 if (inside_loop_controll_4==1)
                                 {
                                     cout <<"Enter the Hospital Name ::";
                                     getline(cin, store_strings_4);
                                     HospitalInfo.sethospitalname(store_strings_4);
                                }
                                
                                else if (inside_loop_controll_4==2)
                                {
                                      cout <<"Enter the Hospital Location ::";
                                     getline(cin, store_strings_4);
                                     HospitalInfo.sethopitallocation(store_strings_4);
                                    
                                }
                                else if (inside_loop_controll_4==3)
                                {
                                    cout <<"Enter the Hospital Contact Number ::";
                                     getline(cin, store_strings_4);
                                     HospitalInfo.sethopitalcontactnum(store_strings_4);
                                }
                                else 
                                {
                                      cout <<"The screen will be earase after 1.5s ...";
                                    Sleep(1500);
                                    system("CLS");
                                    goto main_menu; 
                                }
                            
                            }  
          
                    
                        }//end  list of the hospital
                        //conditon 5
                        else
                        {
                            Sleep(1500);
                            system("CLS");
                            cout <<"you choose to exit from the System..."<<endl;
                            cout << "THE Data you inserted will be save in the files"<<endl;
                            /*
                             * these operation is to pass the data into the emergancy room and quaratine room
                             * 
                             * 
                             * */
                             for (int x = 0 ; x <counter_doctors ; x++)
                                {HospitalInfo.matchDr(&doctors[x]);}
                                
                            for (int y=0 ; y < counter_nurses; y ++)
                                {HospitalInfo.matchNurses(&nurses[y]);}
                                
                            for (int j=0 ; j <  counter_patients; j++)
                                {HospitalInfo.matchIfectedwithRooms(&infected_Patient[j]);}
                                
                         
                            
                            goto write_data;
                            
                            }
                
                    }   
            }
 
 
 
 
 
 
 
                          
                                
                                
            //this part is for the admin premisions
            //to set up the program                    
            //this part is not to set up the data if the files are empty its to set them based on the login page id the user entered 
            //the admin ID
         admin_part_not_setting_by_id:   
            //this part is to edit and show the data by using the ID for the admin
         if (checkfirstLetter_Admin==true)
        {
            Sleep(1500);
            system("CLS");
            //two types of lists one is to display and another to edit
            main_menu_admin:
                
                int choice;
                cout <<"<<<<<Main Menu>>>>>"<<endl;
                cout <<"Choose one of the Options"<<endl;
                cout <<"1-Display Inforamtion"<<endl;
                cout <<"2-Edit Inforamtion"<<endl;
                cout <<"3- Log out "<<endl;
                cout <<"Enter a Number ::";
                cin >>choice;
                
                if (choice==1) //start 1-Display Inforamtion
                {
                   display_menu: 
                   
                    int number434=434;
                    cout << "<<<Display Menu>>>"<<endl;
                    cout <<"1-Display Patient Data (by ID)"<<endl;
                    cout <<"2-Display Doctor Data (by ID)"<<endl;
                    cout <<"3-Display Nurse Data (by ID)"<<endl;
                    cout <<"4-Display Hospital Inforamtion"<<endl;
                    cout <<"5-Go to the Main Menu"<<endl;
                
                    
                    for (;number434!=5;)
                    {
                        cout <<"Enter a Number ::";
                        cin>>number434;
                      
                        
                        // 1-Display Patient Data (by ID)
                        if (number434==1)
                        {
                            
                        part1_display :
                        
                            string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to display its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_patients ; k++)
                            {
                                if (infected_Patient[k].getPatientID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Patient Menu >>>>"<<endl;
                                    cout <<"1- Display Personal Inforamtion"<<endl;
                                    cout <<"2- Display Spcific Personal Inforamtion"<<endl;
                                    cout <<"3- Display a Summary about the Patient"<<endl;
                                    cout <<"4- Back to Display Menu"<<endl;
                                    cout <<"5- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con!=5;)
                                    {
                                        cout <<"Enter A number from Patient Menu::";
                                        cin>>loop_con;
                                        
                                        if(loop_con==1)
                                        {
                                            infected_Patient[index].DisplayAllPatienInfo();
                                        }
                                        else if (loop_con==2)
                                        {
                                            infected_Patient[index].DisplayaSpcificInfo();
                                        }
                                        else if (loop_con==3)
                                        {
                                            cout <<infected_Patient[index];
                                        }
                                        else if (loop_con==4)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto display_menu;
                                        }
                                        else if (loop_con==5)
                                        {
                                             cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        else
                                        {
                                            cout <<"You Inserted a wrong number ....."<<endl;
                                            
                                        }
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                                        char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto part1_display;}
                                }
                                
                            }// 1-Display Patient Data (by ID) end
                            
                            //2-Display Doctor Data (by ID)
                            else  if (number434==2)
                            {
                                part2_display :
                        
                            string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to display its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_doctors ; k++)
                            {
                                if (doctors[k].getWorkerID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con2=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Doctor Menu >>>>"<<endl;
                                    cout <<"1- Display Doctor Inforamtion"<<endl;
                                    cout <<"2- Display ID's for All Patients Under Supervision"<<endl;
                                    cout <<"3- Display a Summary for All Patients Under Supervision"<<endl;
                                    cout <<"4- Back to Display Menu"<<endl;
                                    cout <<"5- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con2!=5;)
                                    {
                                        cout << "Enter a Number from Doctor Menu:: ";
                                        cin >>loop_con2;
                                        if (loop_con2==1)
                                            {
                                                doctors[index].DisplayWorkerInfo();
                                            }
                                        else if (loop_con2==2)
                                        {
                                             doctors[index].ShowPatientsUnderSuperviosion();
                                            
                                        }
                                      else if (loop_con2==3)
                                      {
                                          
                                          doctors[index].DisplaySummaryAboutPatients();
                                      }
                                      
                                      else if (loop_con2==4)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto display_menu;
                                        }
                                        else if (loop_con2==5)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        
                                        else 
                                        {
                                            cout <<"You Inserted a wrong number ....."<<endl;
                                        }
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                                        char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto part2_display;}
                                }
                                
                            }//end 2-Display Doctor Data (by ID)
                                
                                //3-Display Nurse Data (by ID)
                            else  if (number434==3)
                            {
                            part3_display :
                        
                            string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to display its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_nurses  ; k++)
                            {
                                if (nurses[k].getWorkerID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con2=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Nurse Menu >>>>"<<endl;
                                    cout <<"1- Display Nurse Inforamtion"<<endl;
                                    cout <<"2- Display ID's for All Patients Under Supervision"<<endl;
                                    cout <<"3- Display a Summary for All Patients Under Supervision"<<endl;
                                    cout <<"4- Back to Display Menu"<<endl;
                                    cout <<"5- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con2!=5;)
                                    {
                                        cout << "Enter a Number from Nurse Menu:: ";
                                        cin >>loop_con2;
                                        if (loop_con2==1)
                                            {
                                                nurses[index].DisplayWorkerInfo();
                                            }
                                        else if (loop_con2==2)
                                        {
                                             nurses[index].ShowPatientsUnderSuperviosion();
                                            
                                        }
                                      else if (loop_con2==3)
                                      {
                                          
                                          nurses[index].DisplaySummaryAboutPatients();
                                      }
                                      
                                      else if (loop_con2==4)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto display_menu;
                                        }
                                        else if (loop_con2==5)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        else 
                                        {
                                         cout <<"You Inserted a wrong number ..."<<endl;   
                                        }
                                        
                                      
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                   char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto part3_display;}
                                }
                            } //end 3-Display Nurse Data (by ID)
                            
                            
                            //4-Display Hospital Inforamtion
                            else  if (number434==4)
                            {
                                Hospital_Menu:
                                cout <<"<<<< Hospital Menu >>>>"<<endl;
                                cout <<"1- Display Hospital Inforamtion"<<endl;
                                cout <<"2- Go to Emergancy Room"<<endl;
                                cout <<"3- Go to Quaratine Room"<<endl;
                                cout <<"4- Back to Display Menu"<<endl;
                                cout <<"5- Go to Main Menu"<<endl;
                                
                                int number_inserted=54354;
                                
                                for (;number_inserted!=5;)
                                {
                                    cout <<"Enter a Number from Hospital Menu::";
                                    cin >>number_inserted;
                                    
                                    
                                    if (number_inserted==1)
                                    {
                                        HospitalInfo.displayHosptalInformation();
                                    }
                                    
                                    else if (number_inserted==2)
                                    {
                                        cout <<"YOU WILL GO TO Emergancy Room AFTER 2s....."<<endl;
                                        
                                        Sleep(2000);
                                        system("CLS");
                                        cout <<"<<<< Emergancy Room >>>>"<<endl;
                                        cout <<"1-Display A Summary"<<endl;
                                        cout <<"2- Back to Hospital Menu"<<endl;
                                        int number234=4234;
                                        
                                        for (;number234!=2;)
                                        {
                                            cout <<"Enter a Number from Emergancy Room list::";
                                            cin>>number234;
                                            
                                            if (number234==1)
                                            {HospitalInfo.EMDisplaySummary();}
                                            else if (number234==2)
                                            {    
                                                cout <<"You will Go to  Hospital Menu after 1.5s ..."<<endl;
                                                Sleep(1500);
                                                system("CLS");
                                                goto Hospital_Menu;
                                            }
                                            else 
                                            {
                                                cout <<"You Inserted a wrong number ..."<<endl; 
                                            }
                                        }
                                        
                                        
                                    }
                                    else if (number_inserted==3)
                                    {
                                         cout <<"YOU WILL GO TO Quaratine Room AFTER 2s....."<<endl;
                                        
                                        Sleep(2000);
                                        system("CLS");
                                        cout <<"<<<< Quaratine Room >>>>"<<endl;
                                        cout <<"1-Display A Summary"<<endl;
                                        cout <<"2- Back to Hospital Menu"<<endl;
                                        
                                         int number234=4234;
                                          for (;number234!=2;)
                                        {
                                            cout <<"Enter a Number from Quaratine Room list::";
                                            cin>>number234;
                                            
                                            if (number234==1)
                                            {HospitalInfo.QRDisplaySummary();}
                                            else if (number234==2)
                                            {    
                                                cout <<"You will Go to  Hospital Menu after 1.5s ..."<<endl;
                                                Sleep(1500);
                                                system("CLS");
                                                goto Hospital_Menu;
                                            }
                                            else
                                            {
                                                    cout <<"You Inserted a wrong number ..."<<endl;
                                            }
                                        }
                                        
                                        
                                    }
                                    
                                    else if (number_inserted==4)
                                    {
                                             cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto display_menu;
                                    }
                                    
                                    else if (number_inserted==5)
                                    {
                                        cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin;
                                    }
                                    
                                    else 
                                    {
                                            cout <<"You Inserted a wrong number ..."<<endl;
                                    }
                                    
                                }
                                
                            } //end 4-Display Hospital Inforamtion
                            
                            //5-Go to the Main Menu
                            else  if (number434==5)
                            {       
                                cout <<"you will go to the Main Menu ..."<<endl;
                                 cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin;
                            }//end 5-Go to the Main Menu
                            
                            else 
                            {
                                    cout <<"You Inserted a wrong number ..."<<endl;
                            }
                                
                                
                        }
                        
                        
                    } //end 1-Display Inforamtion
                    
                    
                    
                
                //begining of edit menu
                else if (choice==2)
                {
                    Edit_menu: 
                    int number3334=434;
                       cout << "<<<Edit Menu>>>"<<endl;
                    cout <<"1-Edit Patient Data (by ID)"<<endl;
                    cout <<"2-Edit Doctor Data (by ID)"<<endl;
                    cout <<"3-Edit Nurse Data (by ID)"<<endl;
                    cout <<"4-Edit Hospital Inforamtion"<<endl;
                    cout <<"5-Go to the Main Menu"<<endl;
                    
                    
                    for (;number3334!=5;)
                    {
                        cout <<"Enter A number from Edit Menu::";
                        cin >>number3334;
                        //"1-Edit Patient Data (by ID) begining
                       if  (number3334==1)
                       {
                           edit_part1:
                        
                            string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to edit its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_patients ; k++)
                            {
                                if (infected_Patient[k].getPatientID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con3=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Patient Menu >>>>"<<endl;
                                    cout <<"1- Edit Personal Inforamtion"<<endl;
                                    cout <<"2- Edit Patient ID"<<endl;
                                    cout <<"3- Back to Edit Menu"<<endl;
                                    cout <<"4- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con3!=4;)
                                    {
                                        cout <<"Enter A number from Patient Menu::";
                                        cin>>loop_con3;
                                        
                                        if(loop_con3==1)
                                        {
                                            infected_Patient[index].EditPatientInfo();
                                        }
                                        else if (loop_con3==2)
                                        {
                                            string new_id;
                                            cout<<"Enter the new ID (P****) ::";
                                            cin >>new_id;
                                            infected_Patient[index].setPatientID(new_id);
                                              //this part is to edit the patient id in the quaratine room
                                              HospitalInfo.QRsetIDforRoomRsidents(ID_entered,new_id);
                                              //this part to update the date in the login system
                                              LogIn.updateID_PA(ID_entered,new_id);
                                        }
                                       
                                        else if (loop_con3==3)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto Edit_menu;
                                        }
                                        else if (loop_con3==4)
                                        {
                                             cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        else
                                        {
                                            cout <<"You Inserted a wrong number ....."<<endl;
                                            
                                        }
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                    char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto edit_part1;}
                                }
                        }//"1-Edit Patient Data (by ID) ending
                       
                        else if (number3334==2)//2-Edit Doctor Data (by ID) start
                        {
                            
                            
                             edit_part2 :
                        
                            string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to edit its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_doctors ; k++)
                            {
                                if (doctors[k].getWorkerID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con2=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Doctor Menu >>>>"<<endl;
                                    cout <<"1- Edit Doctor Inforamtion"<<endl;
                                    cout <<"2- Edit Doctor ID"<<endl;
                                    cout <<"3- Add New Patients"<<endl;
                                    cout <<"4- Back to Edit Menu"<<endl;
                                    cout <<"5- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con2!=5;)
                                    {
                                        cout << "Enter a Number from Doctor Menu:: ";
                                        cin >>loop_con2;
                                        if (loop_con2==1)
                                            {
                                                int number434=4343;
                                                cout <<"1- Edit Doctor's Name"<<endl;
                                                cout <<"2- Edit Doctor's PhoneNumber"<<endl;
                                                cout <<"3- Edit Years Of Experience"<<endl;
                                                cout <<"4- Edit Doctor's Specialization"<<endl;
                                                cout <<"5- Exit"<<endl;
                                                string stordate;
                                                
                                                for (;number434!=5;)
                                                {
                                                    cout <<"Enter a Number ::";
                                                    cin >>number434;
                                                    cin.ignore();
                                                    if (number434==1)
                                                      {
                                                          cout <<"Enter the New Name ::";
                                                          getline(cin,stordate);
                                                          doctors[index].setWorkerName(stordate);
                                                        }
                                                    else if (number434==2)
                                                      {
                                                           cout <<"Enter the New PhoneNumber (*No spaces) ::";
                                                           cin>>stordate;
                                                           doctors[index].setWorkerPhoneNumber(stordate);
                                                      }
                                                    else if (number434==3)
                                                      {     int storeint;
                                                          cout <<"Enter Years Of Experience ::";
                                                          cin >>storeint;
                                                          doctors[index].setYearsOfExperience(storeint);
                                                        }
                                                    else if (number434==4)
                                                      {
                                                          cout <<"Enter the New Specialization ::";
                                                          getline(cin,stordate);
                                                          doctors[index].setSpecialization(stordate);
                                                    }
                                                    else
                                                        {break; }
                                                           
                                                }
                                            }
                                            
                                        else if (loop_con2==2)
                                        {
                                            string storeidtem;
                                            cout <<"Enter the new ID (D****) :: ";
                                            cin >>storeidtem;
                                            doctors[index].setWorkerID(storeidtem);
                                            LogIn.updateID_DO(ID_entered,storeidtem);
                                            
                                        }
                                      else if (loop_con2==3)
                                      {
                                          bool foundIDss=false;
                                          string patientid_tem;
                                          cout <<"Enter the Pateint's ID ::";
                                          cin >>patientid_tem;
                                          
                                          
                                          for (int k=0 ; k < counter_patients ; k++)
                                        {
                                        if (infected_Patient[k].getPatientID()==patientid_tem)
                                        {
                                            doctors[index].matchclass(&infected_Patient[k]);
                                            foundIDss=true;
                                            break;
                                        }
                                        }
                                          
                                          if (foundIDss==false)
                                          {cout <<"There is no Patient with this ID ["<<patientid_tem<<"] in the system"<<endl;}
                                      }   
                                      
                                      
                                      else if (loop_con2==4)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto Edit_menu;
                                        }
                                        else if (loop_con2==5)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        
                                        else 
                                        {
                                            cout <<"You Inserted a wrong number ....."<<endl;
                                        }
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                                        char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto edit_part2;}
                                }
                            
                            
                            
                        }//2-Edit Doctor Data (by ID) end
                        
                        else if (number3334==3) //3-Edit Nurse Data (by ID) start
                        {
                            
                            edit_part3:
                            
                                string ID_entered;
                            bool foundID=false;
                            int index;
                            cout <<"Enter the ID That you want to edit its infomraiton::";
                            cin >>ID_entered;
                        
                            for (int k=0 ; k < counter_nurses  ; k++)
                            {
                                if (nurses[k].getWorkerID()==ID_entered)
                                {
                                    foundID=true;
                                    index=k;
                                    break;
                                }
                            }
                                if (foundID==true)
                                {
                                    int loop_con2=434;
                                    
                                    Sleep(1000);
                                    system("CLS");
                                    
                                    cout <<"<<<< Nurse Menu >>>>"<<endl;
                                    cout <<"1- Eidt Nurse's Inforamtion"<<endl;
                                    cout <<"2- Edit Nurse's ID"<<endl;
                                    cout <<"3- Add New Patients"<<endl;
                                    cout <<"4- Back to Edit Menu"<<endl;
                                    cout <<"5- Go to Main Menu"<<endl;
                                    
                                    for (;loop_con2!=5;)
                                    {
                                        cout << "Enter a Number from Nurse Menu:: ";
                                        cin >>loop_con2;
                                        if (loop_con2==1)
                                            {
                                                int number434=4343;
                                                cout <<"1- Edit Nurse's Name"<<endl;
                                                cout <<"2- Edit Nurse's PhoneNumber"<<endl;
                                                cout <<"3- Edit Years Of Experience"<<endl;
                                                cout <<"4- Exit"<<endl;
                                                string stordate;
                                                
                                                for (;number434!=5;)
                                                {
                                                    cout <<"Enter a Number ::";
                                                    cin >>number434;
                                                    cin.ignore();
                                                    if (number434==1)
                                                      {
                                                          cout <<"Enter the New Name ::";
                                                          getline(cin,stordate);
                                                          nurses[index].setWorkerName(stordate);
                                                        }
                                                    else if (number434==2)
                                                      {
                                                           cout <<"Enter the New PhoneNumber (*No spaces) ::";
                                                           cin>>stordate;
                                                           nurses[index].setWorkerPhoneNumber(stordate);
                                                      }
                                                    else if (number434==3)
                                                      {     int storeint;
                                                          cout <<"Enter Years Of Experience ::";
                                                          cin >>storeint;
                                                          nurses[index].setYearsOfExperience(storeint);
                                                        }
                                                    else
                                                        {break; }
                                                           
                                                }
                                            }
                                            
                                        else if (loop_con2==2)
                                        {
                                            string storeidtem;
                                            cout <<"Enter the new ID (N****) :: ";
                                            cin >>storeidtem;
                                            nurses[index].setWorkerID(storeidtem);
                                            LogIn.updateID_NU(ID_entered,storeidtem);
                                           
                                        }
                                      else if (loop_con2==3)
                                      {
                                          bool foundIDss=false;
                                          string patientid_tem;
                                          cout <<"Enter the Pateint's ID ::";
                                          cin >>patientid_tem;
                                          
                                          
                                          for (int k=0 ; k < counter_patients ; k++)
                                        {
                                        if (infected_Patient[k].getPatientID()==patientid_tem)
                                        {
                                            nurses[index].matchclass(&infected_Patient[k]);
                                            foundIDss=true;
                                            break;
                                        }
                                        }
                                          
                                          if (foundIDss==false)
                                          {cout <<"There is no Patient with this ID ["<<patientid_tem<<"] in the system"<<endl;}
                                      }   
                                      
                                      
                                      else if (loop_con2==4)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto Edit_menu;
                                        }
                                        else if (loop_con2==5)
                                        {
                                            cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin; 
                                        }
                                        
                                        else 
                                        {
                                            cout <<"You Inserted a wrong number ....."<<endl;
                                        }
                                    }
                                    
                                        
                                }
                                
                                
                                
                                else if (foundID ==false)
                                {
                                     char letter;
                                    cout <<"There is no matching ID, to insert again enter (Y) ::";
                                    cin >>letter;
                                    if ((letter=='Y')||(letter=='y'))
                                    {goto edit_part3;}
                                }
  
                            
                        }//end 3-Edit Nurse Data (by ID)

                        else if (number3334==4)//4-Edit Hospital Inforamtion start
                        {
                            
                
                                cout <<"<<<< Edit Hospital Information >>>>"<<endl;
                                cout <<"1- Edit Hospital Name"<<endl;
                                cout <<"2- Edit Hopital Location"<<endl;
                                cout <<"3- Edit Hopital Contact Number"<<endl;
                                cout <<"4- Back to Edit Menu"<<endl;
                                cout <<"5- Go to Main Menu"<<endl;
                                
                                int number_inserted=54354;
                                
                                for (;number_inserted!=5;)
                                {
                                    string storedateinserted;
                                    cout <<"Enter a Number from Edit Hospital Information ::";
                                    cin >>number_inserted;
                                    cin.ignore();
                                    
                                    if (number_inserted==1)
                                    {
                                        cout <<"Enter the New Name ::";
                                        getline(cin, storedateinserted);
                                        HospitalInfo.sethospitalname(storedateinserted);
                                    }
                                    else if (number_inserted==2)
                                    {
                                         cout <<"Enter the New Location ::";
                                        getline(cin, storedateinserted);
                                        HospitalInfo.sethopitallocation(storedateinserted);
                                    }
                                    else if (number_inserted==3)
                                    {
                                        cout <<"Enter the New Contact Number ::";
                                        getline(cin, storedateinserted);
                                        HospitalInfo.sethopitalcontactnum(storedateinserted);
                                    }
                                    
                                     else if (number_inserted==4)
                                    {
                                             cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto Edit_menu;
                                    }
                                    
                                    else if (number_inserted==5)
                                    {
                                        cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin;
                                    }
                                    
                                    else 
                                    {
                                            cout <<"You Inserted a wrong number ..."<<endl;
                                    }
                                }
                                
                                
                            
                        }//4-Edit Hospital Inforamtion emd
                        
                        else if (number3334==5)//5-Go to the Main Menu start
                        {
                             cout <<"you will go to the Main Menu ..."<<endl;
                                 cout <<"The Screen will be cleared after 1.5s ..."<<endl;
                                            Sleep(1500);
                                            system("CLS");
                                            goto main_menu_admin;
                        }//end 5-Go to the Main Menu
                        
                        else //chose a wrong number 
                        {
                                cout <<"You Inserted a wrong number ..."<<endl;
                        }//chose a wrong number  end 
 
                    }
                    
                }   //Ending of edit menu
                    
                    
                    
                else if (choice==3)
                    
                    {
                        cout <<"Log out successfully..."<<endl;
                        Sleep(1500);
                        system("CLS");
                        goto logingpage;
                    }
                else 
                {
                    char letter;
                    cout <<"You inserted an a wrong number, to try again enter (Y) ::";
                    cin >>letter;
                    if ((letter=='Y')||(letter=='y'))
                        {goto main_menu_admin;}
                    
                    
                }
        }




    /*
     * this part is for the Nurse , it allows him to do some operations based on his/her permisions 
     * */
    Doctor_controll:
    if (checkfirstLetter_Doctor==true)
    {
        
        Sleep(1500);
        system("CLS");
        
        
        
        int dr_index;
        for (int i = 0; i <counter_doctors ; i++ )
        {
            
            if (doctors[i].getWorkerID()==signinID)
                {dr_index=i;
                break;}
            
        }
        
        main_menu_dr:
                int choice;
                cout <<"<<<<<Main Menu>>>>>"<<endl;
                cout <<"Choose one of the Options"<<endl;
                cout <<"1-Display Inforamtion"<<endl;
                cout <<"2-Edit Inforamtion"<<endl;
                cout <<"3- Log out "<<endl;
                cout <<"Enter a Number ::";
                cin >>choice;
                
            if (choice==1) //start Display Inforamtion
            {
                cout <<"You will move to the chosen Menu after 1.5s..."<<endl;
                Sleep(1500);
                system("CLS");
                
                cout <<"<<<< Display Menu >>>>"<<endl;
                cout <<"1- Display Doctor Infomation"<<endl;
                cout <<"2- Display A Summary about The Patients"<<endl;
                cout <<"3- Display Patients IDs"<<endl;
                cout << "4- Display Inforamtion about a Specific patinet (by ID)"<<endl;
                cout <<"5- Display Daily Check for a Specific patinet (by ID) "<<endl;
                cout <<"6- Show All Symptoms for a Specific patinet (by ID)"<<endl;
                cout <<"7-Back To Main Menu"<<endl;
                
                int entered_num=43443;
                
                for (;entered_num!=7;)
                {
                    cout <<"Enter a number from Display Menu::";
                    cin >> entered_num;
                    
                    if (entered_num==1)
                    {
                        doctors[dr_index].DisplayWorkerInfo();
                    }
                    else if (entered_num==2)
                    {
                    doctors[dr_index].DisplaySummaryAboutPatients();
                    }
                     else if (entered_num==3)
                     {
                         doctors[dr_index].ShowPatientsUnderSuperviosion();
                    }
                     else if (entered_num==4)
                     {
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         doctors[dr_index].DisplaySpecificPatientInfo(id_p);
                    }
                    else if (entered_num==5)
                     {
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=doctors[dr_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                             char decide;
                             int day;
                             cout <<"Do you want to display all days Y/N ::";
                             cin >>decide;
                             if ((decide=='Y')||(decide=='y'))
                             {
                                 pointertopatient->getdailycheck(3,true);
                            }
                            
                             else if ((decide=='N')||(decide=='n'))
                             {
                                 cout <<"Enter a the Day Number [1-3] ::";
                                 cin >>day;
                                 pointertopatient->getdailycheck(day,false);
                            }
                             
                            }
                            
                    }
                    else if (entered_num==6)
                            {
                                  string id_p;
                                cout <<"Enter the patient's ID ::";
                                cin>>id_p;
                                doctors[dr_index].show_symptoms_for_patient(id_p);
                            }
                        else if (entered_num==7)
                        {
                            cout <<"You will go to the Main Menu after 1.5s...."<<endl;
                            Sleep(1500);
                            system("CLS");
                            goto main_menu_dr;
                            }
                        
                       else //chose a wrong number 
                        {
                                cout <<"You Inserted a wrong number ..."<<endl;
                        }//chose a wrong number  end 
                }
                
                
            } //end Display Inforamtion
            
            
            else if (choice==2) //start 2-Edit Inforamtion
            {
              
                cout <<"You will move to the chosen Menu after 1.5s..."<<endl;
                Sleep(1500);
                system("CLS");
                
                
                edit_menu_dr:
                
                cout <<"<<<< Edit Menu >>>>"<<endl;
                 cout <<"1- Edit Daily Check for a spcific patient (by ID)"<<endl;
                 cout <<"2- Edit Patient Condition for a spcific patient (by ID)"<<endl;
                 cout <<"3- Edit Symptoms for a spcific patient (by ID) "<<endl;
                cout <<"4-Back To Main Menu"<<endl;
                
                int entered_num=43443;
                
                for (;entered_num!=4;)
                {
                    cout <<"Enter a number from Edit Menu::";
                    cin >> entered_num;
                    
                    if (entered_num==1)
                    {
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=doctors[dr_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                            daily_check_set:
                                char check32;
                                int day;
                                cout <<"Enter a the Day Number [1-3] ::";
                                cin >>day;
                                day=day-1;
                                pointertopatient->setDataFordailycheck(day);
                            cout <<"If you Want to Edit Another Day please enter (Y) ::";
                            cin >>check32;

                            if ((check32=='Y')||(check32=='y'))
                            { goto daily_check_set;
                            }
                            else 
                            {
                                cout <<"You chose to not edit any other day ...."<<endl;
                            }
                         }
                              else
                        {
                            cout<<"You inseted a wrong ID ..."<<endl;
                            cout<<"You will go to edit menu after 1.5s"<<endl;
                               Sleep(1500);
                                system("CLS");
                                goto edit_menu_dr;
                        }
                        
                    }
                    else if (entered_num==2)
                    {
                        string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                        doctors[dr_index].EditPatientInforamtion(id_p);
                    }
                     else if (entered_num==3)
                     {
                        Sleep(1500);
                        system("CLS");
                         cout <<"1-Display All Symptoms"<<endl;
                         cout <<"2- Edit a Symptom"<<endl;
                         cout <<"3- Back to Edit Menu"<<endl;
                         int enter_num=4343;
                         
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=doctors[dr_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                         for (;enter_num!=3;)
                         {
                             cout <<"Enter a number ::";
                             cin >>enter_num;
                             cin.ignore();
                            
                            if (enter_num==1)
                            {
                                for (int k=0 ; k <7 ; k++)
                                {
                                    cout <<"Symptom ["<<k+1<<"] ::"<<pointertopatient->GetSymptoms(k)<<endl;
                                }
                                
                            }
                            else if (enter_num==2)
                            {
                                string new_Symptom;
                                int Symptom_num;
                                cout <<"Enter the Symptom Number that you want to Edit ::";
                                cin >>Symptom_num;
                             //   getline(cin,Symptom_num);
                                cin.ignore();
                                Symptom_num=Symptom_num-1;
                                cout <<"Enter the new Symptom_num ::";
                                getline(cin ,new_Symptom);
                                pointertopatient->SetSymptoms(Symptom_num,new_Symptom);
                                
                            }
                            else if (enter_num==3)
                            {
                                cout <<"You choose to go to Edit Menu ...."<<endl;
                                cout <<"You will go after 1.5s ..."<<endl;
                                 Sleep(1500);
                                system("CLS");
                                goto edit_menu_dr;
                                }
                            else 
                            {
                                    cout <<"You Inserted a wrong number ..."<<endl;
                            }
                             
                        }
                        }
                        else
                        {
                            cout<<"You inseted a wrong ID ..."<<endl;
                            cout<<"You will go to edit menu after 1.5s"<<endl;
                               Sleep(1500);
                                system("CLS");
                                goto edit_menu_dr;
                        }
                        
                         
                    }
                    
                    
                    
                     else if (entered_num==4)
                     {
                        cout <<"You will go to the Main Menu after 1.5s...."<<endl;
                            Sleep(1500);
                            system("CLS");
                            goto main_menu_dr; 
                    }
                    
                        
                       else //chose a wrong number 
                        {
                                cout <<"You Inserted a wrong number ..."<<endl;
                        }//chose a wrong number  end 
                }
            
  
            } //end 2-Edit Inforamtion
            
            
            else if (choice==3)//start 3- Log out 
            {
                        cout <<"Log out successfully..."<<endl;
                        Sleep(1500);
                        system("CLS");
                        goto logingpage;
            }//end 3- Log out 
            
            else 
            {
                    char letter;
                    cout <<"You inserted an a wrong number, to try again enter (Y) ::";
                    cin >>letter;
                    if ((letter=='Y')||(letter=='y'))
                        {goto main_menu_dr;}
            }
        
    }
    
    
     /*
     * this part is for the Nurse , it allows him to do some operations based on his/her permisions 
     * */
    Nurse_controll:
     if (checkfirstLetter_Nurse==true)
    {
        Sleep(1500);
        system("CLS");
        int nur_index;
        for (int i = 0; i <counter_nurses ; i++ )
        {
            
            if (nurses[i].getWorkerID()==signinID)
                {nur_index=i;
                break;}
            
        }
        
        main_menu_nur:
                int choice;
                cout <<"<<<<<Main Menu>>>>>"<<endl;
                cout <<"Choose one of the Options"<<endl;
                cout <<"1-Display Inforamtion"<<endl;
                cout <<"2-Edit Inforamtion"<<endl;
                cout <<"3- Log out "<<endl;
                cout <<"Enter a Number ::";
                cin >>choice;
                
            if (choice==1) //start Display Inforamtion
            {
                cout <<"You will move to the chosen Menu after 1.5s..."<<endl;
                Sleep(1500);
                system("CLS");
           
        display_menu_nurse:
        
                cout <<"<<<< Display Menu >>>>"<<endl;
                cout <<"1- Display Nurse Infomation"<<endl;
                cout <<"2- Display A Summary about The Patients"<<endl;
                cout <<"3- Display Patients IDs"<<endl;
                cout << "4- Display Inforamtion about a Specific patinet (by ID)"<<endl;
                cout <<"5- Display Daily Check for a Specific patinet (by ID) "<<endl;
                cout <<"6- Show All Symptoms for a Specific patinet (by ID)"<<endl;
                cout <<"7- Display Quaratine Inforamtion for a Specific patinet (by ID)"<<endl;
                cout <<"8-Back To Main Menu"<<endl;
                
                int entered_num=43443;
                
                for (;entered_num!=7;)
                {
                    cout <<"Enter a number from Display Menu::";
                    cin >> entered_num;
                    
                    if (entered_num==1)
                    {
                        nurses[nur_index].DisplayWorkerInfo();
                    }
                    else if (entered_num==2)
                    {
                
                    nurses[nur_index].DisplaySummaryAboutPatients();
                    }
                     else if (entered_num==3)
                     {
                         nurses[nur_index].ShowPatientsUnderSuperviosion();
                    }
                     else if (entered_num==4)
                     {
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         nurses[nur_index].DisplaySpecificPatientInfo(id_p);
                    }
                    else if (entered_num==5)
                     {
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=nurses[nur_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                             char decide;
                             int day;
                             cout <<"Do you want to display all days Y/N ::";
                             cin >>decide;
                             if ((decide=='Y')||(decide=='y'))
                             {
                                 pointertopatient->getdailycheck(3,true);
                            }
                            
                             else if ((decide=='N')||(decide=='n'))
                             {
                                 cout <<"Enter a the Day Number [1-3] ::";
                                 cin >>day;
                                 pointertopatient->getdailycheck(day,false);
                            }
                             
                            }
                    }
                    else if (entered_num==6)
                            {
                                  string id_p;
                                cout <<"Enter the patient's ID ::";
                                cin>>id_p;
                                nurses[nur_index].show_symptoms_for_patient(id_p);
                            }
                            
                        else if (entered_num==7)
                        {
                            Sleep(1500);
                            
                         Quaratine_Inforamtion:
   
                            system("CLS");
                            
                            cout <<"<<< Quaratine Inforamtion >>>"<<endl;
                            cout <<"1- Display Entering Date "<<endl;
                            cout <<"2- Display Exiting Date "<<endl;
                            cout <<"3- Display Days Spent"<<endl;
                            cout <<"4- Back to Display Menu"<<endl;
                            id_entered32333:   
                            string id_entered;
                            cout <<"Enter the Patient ID ::";
                            cin >>id_entered;
                            if (nurses[nur_index].CheckPateintID(id_entered)==true)
                            {
                                int number_entered=4342;
                               
                                for (;number_entered!=4;)
                                {
                                     cout <<"Enter a Number from Quaratine Inforamtion list::";
                                    cin >>number_entered;
                                
                                if (number_entered==1)
                                    {
                                        cout <<"The Entering Date is ::"<<HospitalInfo.QRgetStartingDateByID(id_entered)<<endl;
                                    }
                                else if (number_entered==2)
                                {
                                    cout <<"The Exiting Date is ::"<<HospitalInfo.QRgetExitingDateByID(id_entered)<<endl;
                                }
                                else if (number_entered==3)
                                {
                                    cout <<"Number of Spent Days ::"<<HospitalInfo.QRgetNumberOfDaysSpentForspecificID(id_entered)<<endl;
                                }
                                else if (number_entered==4)
                                {
                                    cout <<"you will go back to the Display Menu After 1.5"<<endl;
                                     Sleep(1500);
                                      system("CLS");
                                    goto display_menu_nurse;  
                                }
                                else 
                                {
                                    cout << "You entered a wrong number..."<<endl;
                                }
                                
                                
                                }
                                
                            }
                            
                            else{
                                char decided;
                                cout <<"There is no matching ID..."<<endl;
                                cout <<"To try Again Enter (Y) ::";
                                cin>>decided;
                                if ((decided=='y')||(decided=='Y'))
                                    {goto id_entered32333;}
                                else 
                                {
                                    goto Quaratine_Inforamtion;
                                }
                                    
                                }
                            
                            
                        }
                        else if (entered_num==8)
                        {
                            cout <<"You will go to the Main Menu after 1.5s...."<<endl;
                            Sleep(1500);
                            system("CLS");
                            goto main_menu_nur;
                            }
                        
                       else //chose a wrong number 
                        {
                                cout <<"You Inserted a wrong number ..."<<endl;
                        }//chose a wrong number  end 
                }
                
                
            } //end Display Inforamtion
            
            
            else if (choice==2) //start 2-Edit Inforamtion
            {
              
                cout <<"You will move to the chosen Menu after 1.5s..."<<endl;
                Sleep(1500);
                
                edit_menu_nur:
                system("CLS");
                
                
                
                
                cout <<"<<<< Edit Menu >>>>"<<endl;
                 cout <<"1- Edit Daily Check for a spcific patient (by ID)"<<endl;
                 cout <<"2- Edit Quaratine Information for a spcific patient (by ID)"<<endl; //will be changed into quaratine room
                 cout <<"3- Edit Symptoms for a spcific patient (by ID) "<<endl;
                cout <<"4-Back To Main Menu"<<endl;
                
                int entered_num=43443;
                
                for (;entered_num!=4;)
                {
                    cout <<"Enter a number from Edit Menu::";
                    cin >> entered_num;
                    
                    if (entered_num==1)
                    {
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=nurses[nur_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                            daily_check_set32:
                                char check32;
                                int day;
                                cout <<"Enter a the Day Number [1-3] ::";
                                cin >>day;
                                day=day-1;
                                pointertopatient->setDataFordailycheck(day);
                            cout <<"If you Want to Edit Another Day please enter (Y) ::";
                            cin >>check32;

                            if ((check32=='Y')||(check32=='y'))
                            { goto daily_check_set32;
                            }
                            else 
                            {
                                cout <<"You chose to not edit any other day ...."<<endl;
                            }
                         }
                              else
                        {
                            cout<<"You inseted a wrong ID ..."<<endl;
                            cout<<"You will go to edit menu after 1.5s"<<endl;
                               Sleep(1500);
                                system("CLS");
                                goto edit_menu_nur;
                        }
                        
                         
                    }
                    else if (entered_num==2)
                    {
                        
                       if (nurses[nur_index].getWorkingRoom()=="QuaratineRoom")
                       {
                            id_entered332:   
                            string id_entered;
                            cout <<"Enter the Patient ID ::";
                            cin >>id_entered;
                            if (nurses[nur_index].CheckPateintID(id_entered)==true)
                             {
                                    HospitalInfo.QREditQuDetailsForPatient(id_entered);
                                 
                            }
                                
                                else{
                                char decided;
                                cout <<"There is no matching ID..."<<endl;
                                cout <<"To try Again Enter (Y) ::";
                                cin>>decided;
                                if ((decided=='y')||(decided=='Y'))
                                    {goto id_entered332;}
                                else 
                                {
                                    goto edit_menu_nur;
                                }
                                    
                                }
                        }
                        else
                        {
                            cout<<"The Nurse is not working the the QuaratineRoom ..."<<endl;
                            }
                    }
                     else if (entered_num==3)
                     {
                        Sleep(1500);
                        system("CLS");
                         cout <<"1-Display All Symptoms"<<endl;
                         cout <<"2- Edit a Symptom"<<endl;
                         cout <<"3- Back to Edit Menu"<<endl;
                         int enter_num=4343;
                         
                         Infected *pointertopatient;
                         string id_p;
                        cout <<"Enter the patient's ID ::";
                        cin>>id_p;
                         pointertopatient=nurses[nur_index].ReturnPatientObjectAddress(id_p);
                         if (pointertopatient!=nullptr)
                         {
                         for (;enter_num!=3;)
                         {  cout <<"Enter a number from the above list ::";
                             cin >>enter_num;
                             cin.ignore();
                            
                            if (enter_num==1)
                            {
                                for (int k=0 ; k <7 ; k++)
                                {
                                    cout <<"Symptom ["<<k+1<<"] ::"<<pointertopatient->GetSymptoms(k)<<endl;
                                }
                                
                            }
                            else if (enter_num==2)
                            {
                                string new_Symptom;
                                int Symptom_num;
                                cout <<"Enter the Symptom Number that you want to Edit ::";
                                
                                cin >>Symptom_num;
                                cin.ignore();
                                Symptom_num=Symptom_num-1;
                                cout <<"Enter the new Symptom_num ::";
                                getline(cin ,new_Symptom);
                                pointertopatient->SetSymptoms(Symptom_num,new_Symptom);
                                
                            }
                            else if (enter_num==3)
                            {
                                cout <<"You choose to go to Edit Menu ...."<<endl;
                                cout <<"You will go after 1.5s ..."<<endl;
                                 Sleep(1500);
                                system("CLS");
                                goto edit_menu_nur;
                                }
                            else 
                            {
                                    cout <<"You Inserted a wrong number ..."<<endl;
                            }
                             
                        }
                        }
                            else
                        {
                            cout<<"You inseted a wrong ID ..."<<endl;
                            cout<<"You will go to edit menu after 1.5s"<<endl;
                               Sleep(1500);
                                system("CLS");
                                goto edit_menu_nur;
                        }
                         
                    }
                    
                    
                    
                     else if (entered_num==4)
                     {
                        cout <<"You will go to the Main Menu after 1.5s...."<<endl;
                            Sleep(1500);
                            system("CLS");
                            goto main_menu_nur; 
                    }
                    
                        
                       else //chose a wrong number 
                        {
                                cout <<"You Inserted a wrong number ..."<<endl;
                        }//chose a wrong number  end 
                }
            
  
            } //end 2-Edit Inforamtion
            
            
            else if (choice==3)//start 3- Log out 
            {
                        cout <<"Log out successfully..."<<endl;
                        Sleep(1500);
                        system("CLS");
                        goto logingpage;
            }//end 3- Log out 
            
            else 
            {
                    char letter;
                    cout <<"You inserted an a wrong number, to try again enter (Y) ::";
                    cin >>letter;
                    if ((letter=='Y')||(letter=='y'))
                        {goto main_menu_nur;}
            }
        
    }
    
  
    /*
     * this part is for the patient , it allows him to do some operations based on his/her permisions 
     * */
    Patient_controll:
    if (checkfirstLetter_Patient==true)
    {
        
         int pa_index;
        for (int i = 0; i <counter_patients ; i++ )
        {
            
            if (infected_Patient[i].getPatientID()==signinID)
                {pa_index=i;
                break;}
        }
        
       
           int choice=54545;
                cout <<"<<<<<Patient Menu>>>>>"<<endl;
                cout <<"Choose one of the Options"<<endl;
                cout <<"1-Display Personal Inforamtion"<<endl;
                cout <<"2-Display a Summary"<<endl;
                cout <<"3-Display a specific inforamtion"<<endl;
                cout <<"4- Log out "<<endl;
        for (;choice!=4;)
        {
            cout <<"Enter you Option ::";
            cin >>choice;
            
            if (choice==1)
            {
                
                infected_Patient[pa_index].DisplayAllPatienInfo();
            }
            
            else if (choice==2)
            {
                 cout <<infected_Patient[pa_index];
            }
            
            else if (choice==3)
            {
                infected_Patient[pa_index].DisplayaSpcificInfo();
            }
            else if (choice==4)
            {
                 cout <<"Log out successfully..."<<endl;
                        Sleep(1500);
                        system("CLS");
                        goto logingpage;
            }
            else 
            {
               cout <<"You entered a wrong number...."<<endl; 
            }
        }
        
    }
    
    
    
    //this part will be for writing the data in the file

    write_data:

   P_read_write.clear();
  
     if (patientFile_was_empty==true)
     {
    P_read_write.seekp(0);
    P_read_write<<number_of_Patients<<endl;
   P_read_write<<counter_patients<<endl;
    //  P_read_write.seekp(5);
     }
      else  if (patientFile_was_empty==false)
     {
    P_read_write.seekp(0);
    P_read_write<<number_of_Patients<<endl;
    if (counter_patients>9)
    {
    P_read_write<<counter_patients<<endl;
    P_read_write.seekp(6);
    }
    else 
    {
    P_read_write<<counter_patients<<endl;
    P_read_write.seekp(4);
    }
     }
          
  
    
     for (int i=0 ; i < counter_patients;i++)
     {
         P_read_write<<infected_Patient[i].getpatientname()<<","<<infected_Patient[i].getpatientphonenumber()<<","<<infected_Patient[i].getpatientaddress()<<","
         <<infected_Patient[i].getCurrentRoom()<<","<<infected_Patient[i].getPatientConditon()<<","<<infected_Patient[i].getPatientID()<<endl;
         
         for (int k=0 ; k <7 ; k ++)
         {
             if (k==6)
             {
                 P_read_write<<infected_Patient[i].GetSymptoms(k);
                 break;
            }
              P_read_write<<infected_Patient[i].GetSymptoms(k)<<",";
        }
        P_read_write<<endl;
          
          
          for (int j=0; j <3 ; j++)
          {
             
             /*  P_read_write<<infected_Patient[i].Da_getNewsymptoms(j,0)<<","<<infected_Patient[i].Da_getNewsymptoms(j,1)<<","<<infected_Patient[i].Da_getMedicine(j)<<","<<infected_Patient[i].Da_getBreakFast(j)<<","
               <<infected_Patient[i].Da_getLunch(j)<<","<<infected_Patient[i].Da_getDinner(j)<<","<<infected_Patient[i].Da_getDrinks(j)<<endl;*/
               
               P_read_write<<infected_Patient[i].getdaildddycheck(j)<<endl;
               
        }
        
        
    }
    P_read_write.close();
    
    //saving the data for the doctors files
    D_read_write.clear();
    if (doctorsFile_was_empty==true)
    {
        
   D_read_write.seekp(0);
    D_read_write<<number_of_Doctors<<endl;
   //  D_read_write<<counter_doctors<<endl;
       // D_read_write.seekp(5);
          if (counter_doctors>9)
    {
        D_read_write<<counter_doctors<<endl;
        D_read_write.seekp(7);
    }
    else 
    {
    D_read_write<<counter_doctors<<endl;
    D_read_write.seekp(5);
    }
        
    }
    
    else if  (doctorsFile_was_empty==false)
    {
   D_read_write.seekp(0);
    D_read_write<<number_of_Doctors<<endl;
      
          if (counter_doctors>9)
    {
        D_read_write<<counter_doctors<<endl;
        D_read_write.seekp(6);
    }
    else 
    {
    D_read_write<<counter_doctors<<endl;
    D_read_write.seekp(4);
    }
    
    }
    
    for (int y=0 ; y <counter_doctors ; y++)
        {
            D_read_write<< doctors[y].getWorkerName()<<","<<doctors[y].getWorkerID()<<","<<doctors[y].getWorkerPhoneNumber()<<","<<doctors[y].getSpecialization()<<","<<doctors[y].getWorkingRoom()<<","<<doctors[y].getYearsOfExperience()<<endl;
            
            for (int j = 0 ; j < doctors[y].returnIndexcounter(); j++)
            {
               if (j==6)
                {
                     D_read_write <<doctors[y].writepatintsID(j);
                     break;
                }
                D_read_write <<doctors[y].writepatintsID(j)<<endl;
                
            }
            
            if (doctors[y].returnIndexcounter()<7)
            {
                for (int r=0 ; r < (7-doctors[y].returnIndexcounter());r++)
                {
                    if (r==6)
                    {D_read_write<<"Null";
                    break;}
                    D_read_write<<"Null"<<endl;
                   
                }
            }
           //D_read_write<<endl;
        }
        
        
   D_read_write.close();
  
        
    //saving the data for the Nurses file
        N_read_write.clear();
        if (nursesFile_was_empty==true)
        {
        N_read_write.seekp(0);
        N_read_write<<number_of_Nurses<<endl;
        
    if (counter_nurses>9)
    {
        N_read_write<<counter_nurses<<endl;
        N_read_write.seekp(7);
    }
    else 
    {
    N_read_write<<counter_nurses<<endl;
    N_read_write.seekp(5);
    }
      // N_read_write<<counter_nurses<<endl;
     // N_read_write.seekp(5);   

        }
        else if (nursesFile_was_empty==false) 
        {
        N_read_write.seekp(0);
        N_read_write<<number_of_Nurses<<endl;
        if (counter_nurses>9)
    {
        N_read_write<<counter_nurses<<endl;
        N_read_write.seekp(6);
    }
    else 
    {
    N_read_write<<counter_nurses<<endl;
    N_read_write.seekp(4);
    }
        }
          for (int y=0 ; y <counter_nurses ; y++)
        {
            N_read_write<< nurses[y].getWorkerName()<<","<<nurses[y].getWorkerID()<<","<<nurses[y].getWorkerPhoneNumber()<<","<<nurses[y].getWorkingRoom()<<","<<nurses[y].getYearsOfExperience()<<endl;
            
            for (int j = 0 ; j < nurses[y].returnIndexcounter(); j++)
            {
               if (j==6)
               {
                     N_read_write <<nurses[y].writepatintsID(j);
                     break;
                }
                N_read_write <<nurses[y].writepatintsID(j)<<endl;
            }
            
            if (nurses[y].returnIndexcounter()<7)
            {
                for (int r=0 ; r < (7-nurses[y].returnIndexcounter());r++)
                    {
                         if (r==6)
                      {N_read_write<<"Null";
                      break;}
                        N_read_write<<"Null"<<endl;
                   
                    }
                
            }
      //     N_read_write<<endl;
        }
    N_read_write.close();
      //saving the data for the Patients file
    
   
    
    HGI_read_write.clear();
    HGI_read_write.seekp(0);
    HGI_read_write<<HospitalInfo.gethopitallocation()<<","<<HospitalInfo.gethospitalname()<<","<<HospitalInfo.gethopitalcontactnum()<<endl;
    for  (int i=0 ;i <counter_patients ;i++ )
    {
        HGI_read_write<<HospitalInfo.QRgetRoomResidents(i)<<endl;
        
    }
        HGI_read_write.close();
          
 /*  QRoom_read_write.clear();
   QRoom_read_write.seekp(0);
   
   for (int i = 0 ; i < 1; i++)
   {
 cout <<HospitalInfo.QRgetRoomResidents(i)<<endl;
    string store="fsdfdsf";
   // store=HospitalInfo.QRgetRoomResidents(i);
   QRoom_read_write<<store<<endl;
  
   }*/
   
   
  
 //  QRoom_read_write.close();
    return 0;}
    