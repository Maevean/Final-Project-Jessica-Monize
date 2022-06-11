// Final Project Jessica Monize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//Name and rank file I/O function
void myMemoryName()
{
    fstream f;
    string yourName;
    string nameStr;
    string shipName;
    char usrInput;
    cout << "\t~+~+~+~+~+~+~+~+~+~+~+~+~+\n";
    cout << "\t|Welcome to Space Time|" << endl;
    cout << "\t~+~+~+~+~+~+~+~+~+~+~+~+~+\n";
    cout << "To read your saved name and score, enter 'r'. For Write, enter 'w'." << endl;
    cin >> usrInput; //begin user input code
    if (usrInput == 'r') //code for reading the file
    {
        f.open("myMemoryNameTxt", ios::in);
        string str;
        while (getline(f, str))
        {
            cout << str << endl;
        }
        f.close();
    }
    else { //code for writing the file
        f.open("myMemoryNameTxt", ios::out | ios::in | ios::app);
        cout << "Did you make it to the launch pad in time this round? Type Win or Fail" << endl;
        cin >> nameStr;
        nameStr.append(" ");
        cout << "Now please type in your name" << endl;
        cin >> yourName;
        cout << "Which ship did you choose, CyberStar or GalaxyRunner?" << endl;
        cin >> shipName;
        nameStr.append(yourName);
        nameStr.append(" ");
        nameStr.append(shipName);
        nameStr.append("\n");
        cout << "You typed in " << nameStr << endl;
        f << nameStr;
        f.close();
    }
}//end of I/O function

 //----------
//to lock and unlock 
mutex l;

string threadValue;
string threadInfo;

void rocketLaunch(string thisThread)//rocket function code
{
    {
        l.lock();
        string lSS = thisThread;
        threadValue = thisThread;
        threadInfo = threadInfo + thisThread;
        cout << "\nRocket: " << lSS << endl;
        cout << "\n Cadet: " << threadValue << endl;
        cout << "\n Rockets ready for Liftoff: " << threadInfo << endl;

        //timer between rocket release
        for (int i = 0; i < 3; i++)
        {
            this_thread::sleep_for(chrono::seconds(2));
        }

        l.unlock();

    }

}//end of rocket funct code


int main()
{
    label:
    /*TODO:
    * USE I/O TO STORE SCORE OR SOMETHING
    *Have them choose a rocket. Roll a dice to fill up fuel once it reaches a certain amount, blast off.
    */

    //----------
    // intro varriables
    string player;
    string o;
    int rocketShip;

    //random dice roller
    //srand(time(NULL));
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int randomNumber2 = rand();
    int dice;
    int dice2;
    int dice3;
    

    //introduction
    cout << "\tHello, welcome to the Mars landing pad, please state your name" <<endl;
    cin >> player;
    cout << "\tWelcome " << player << "." << endl;
    cout << "Please type in 'options' to see the rules" << endl;
    cin >> o;
    if (o == "options")
    {//begin options and rules
        cout << "Collect fuel for your rocket by rolling the dice." << endl;
        cout << "Rocket CyberStar gives you a *2 to you roll." << endl;
        cout << "Rocket GalaxyRunner gives you an extra dice roll" << endl;
        cout << "Which will you choose?" << endl;
        cout << "\t type '1' for Cyberstar or '2' for GalaxyRunner." << endl;
    }//end options

    //----------
    cin >> rocketShip;
    //if CyberStar is chosen   
    if (rocketShip == 1)
    {
        cout << "You chose CyberStar!" << endl;
        cout << "\t:::Hurry and refuel yout rocket before liftoff!::" << endl;
        cout << "\t::You must leave before the other rocket!::" << endl; 
        cout << "Rolling the dice." << endl;
        int dice = (rand() % 50) *2;
        cout << "\tYou gained " << dice << " bottles of fuel!" << endl;
        //Second round CyberStar if >=50
        if (dice >=50)
        {
            cout << "\tYou totalled in " << dice << endl;
            cout << "\tYou made it! Hop on before take off!" << endl;
        }
        //Second round CyberStar if less than 50
        else
        {
            
            cout << "Not quite enough fuel yet! Roll again!" << endl;
            cout << "\tRolling the dice." << endl;
            int dice = (rand() % 50) * 2;
            cout << "You gained " << dice << " bottles of fuel!" << endl;          
            cout << "\tYou totalled in " << dice << endl;
                // Third round If dice >=50
                if (dice >=50)
                {
                    cout << "\tYou made it! Hop on before take off!" << endl;
                }
                //Third round, if dice lower than 50
                else {
                    cout << "\tYou did not make it back to the shuttle in time," << endl;
                    cout << "\tthe rockets begin take off without you." << endl;
                }
        }
    }
    //----------
    //if GalaxyRunner is chosen
    else if (rocketShip == 2)
    {      
        cout << "You chose GalaxyRunner" << endl;
        cout << "\t:::Hurry and refuel yout rocket before liftoff!::" << endl;
        cout << "\t::You must leave before the other rocket!::" << endl;
        cout << "Rolling the dice." << endl;
        int dice2 = (rand() % 50);
        cout << "\tYou gained " << dice2 << " bottles of fuel!" << endl;
        cout << "Rolling again" << endl;
        int dice3 = (rand() % 50);
        cout << "\tYou gained " << dice3 << " fuel" << endl;
        cout << "Totalling in " << dice2 + dice3 << " bottles of fuel" << endl;
        //Second round GalaxyRunner if >=50
        if (dice2+dice3 >= 50)
        {
            cout << "\tYou made it! Hop on before take off!" << endl;
        }
        //Second round GalaxyRunner if <=50
        else
        {
            cout << "Not quite enough fuel yet! Roll again!" << endl;
            int dice2 = (rand() % 50);
            cout << "You gained " << dice2 << " bottles of fuel!" << endl;
            int dice3 = (rand() % 50);
            cout << "You gained " << dice3 << " fuel" << endl;
            cout << "Totalling in " << dice2 + dice3 << " bottles of fuel" << endl;
            // Third round If dice >=50
            if (dice2+dice3 >= 50)
            {
                cout << "\tYou made it! Hop on before take off!" << endl;
            }
            //Third round, if dice lower than 50
            else {
                cout << "\tYou did not make it back to the shuttle in time," << endl;
                cout << "\tthe rockets begin take off without you." << endl;
            }
        }
    }

    

    //----------
    //start of countdown timer and its vars
    int j = 11;
    int counter = 0;
    while (j > counter)
    {
        j--;
        cout << j << endl;
        for (int i = 0; i < 1; i++)
        {
            this_thread::sleep_for(chrono::seconds(1));
        }//end of countdown
    }

    //----------
    cout << "\tBLAST OFF!!!" << endl;
    //start of rockets launching
    thread t1{ rocketLaunch, "CyberStar Rocket Launching! " };
    thread t2{ rocketLaunch, "GalaxyRunner Rocket Launching! " };

    //checking if threads area available to join
    if (t1.joinable())
    {
        cout << "CyberStar is available to join, launching now!" << endl;
        t1.join();
    }
    if (t2.joinable())
    {
        cout << "GalaxyRunner is available to join, launching now!" << endl;
        t2.join();
    }

    //----------
    //Begin Name and score
    char ui;
    while (true)
    {
        //call in function for name and score
        myMemoryName(); 
        //would you like to replay?
        cout << "do you want to continue 'y' for yes" << endl;
        cin >> ui;
        if (ui != 'y')
        {          
            break;
        }

    }//end name and score

        //replay!
    cout << "\t~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~\n";
    char z;
    cout << " Play Again? (y/n)";
    cin >> z;
    if (z == 'y' || z == 'Y')
        goto label;
} //end int main

