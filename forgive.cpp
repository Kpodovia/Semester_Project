#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void encryptDecrypt(char *input,char *output){
	char key[]={'P','F','L'};
	int keyLength = sizeof(key)/sizeof(*key);
	int i;
	
	for (i=0;i<strlen(input); i++){
		output[i]=input[i] ^ key[i%keyLength];}} 

int main(int argc, char** argv) {
     
	        //VARIABLES
	string username, password, enteredPassword,oldUsername, programPassword="forgive123";
	char encrypted[100], decrypted[100], choice,option;
	
  
  	while(true){
     	  //MAIN MENU
		cout<<"**********PASSWORD MANAGER PROGRAM*********\n";
		cout<<"\n";
		cout<<"1. SAVE CREDENTIALS.\n2. RETRIEVE A SAVED CREDENTIAL.\n3. EXIT PROGRAM.\n";
		cout<<"SELECT 1-3: ";
		cin>>choice;
		cin.ignore();
		
		//OPTION 1
		if(choice=='1'){
			bool available=true;
			ofstream file("Saved passwords.txt", ios::app);
			cout<<"Enter the Username of the Account: ";
			getline(cin, username);
			cout<<"Enter the Password of the Account: ";
			getline(cin, password);
			encryptDecrypt(&password[0], encrypted);
			file<<username<<" "<<encrypted<<endl;
			file.close();
			cout<<" "<<endl;
			cout<<"Username :"<<username<<endl;
			cout<<"Password :"<<password<<endl;
			cout<<"Press 1 to confirm and save the credential or 2 to exit :";
			cin>>option;
			if(option=='1'){cout<<"Credentials saved successfully.";break;}
			else cout<<"Saving failed. Exiting...";break;}
		
		//  OPTION 2
		else if(choice=='2'){
			ifstream file("Saved passwords.txt");
			bool found=false;
			cout<<"Enter the username: ";
			getline(cin, oldUsername);
			while(file>>username>>encrypted){
				encryptDecrypt(encrypted,decrypted);
				if(oldUsername==username){
					found=true;
	cout<<"Enter program password to proceed: ";
	getline(cin, enteredPassword);
	if(enteredPassword!=programPassword){
	cout<<"Incorrect Program Password input. Exiting\n";return 0;}
					else cout<<"The password for "<<username<<" is "<<decrypted<<endl;return 0;}}
					file.close();
					if(!found){
				cout<<"Username not found."; return 0;}}
				
		
		//OPTION 3
		 else if(choice=='3'){
			cout<<"Thank you for using our program.\nProgram Exiting..."; break;}
			
		//INVALID OPTION
		else cout<<"\nInvalid Input.\nPlease Try Again.\n \n";
		}}

	

	
	

