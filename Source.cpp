#include<iostream>
#include"Graph.h"
using namespace std;

int main()
{
    graph g1(4);
 
    int choice;
    system("Color 0A");
    cout << "\n\n\t\t\t\t\t        Network Analysis Using Graphs        " << endl
        << "\t\t\t\t==============================================================" << endl
        << "\t\t\t\t                             MENU                             " << endl
        << "\t\t\t\t-------------------------************-------------------------" << endl
        << "\t\t\t       || \t[1]  No. of Nodes                                     ||" << endl
        << "\t\t\t       || \t[2]  No. of Edges                                     ||" << endl
        << "\t\t\t       || \t[3]  No. of Source Nodes                              ||" << endl
        << "\t\t\t       || \t[4]  No. of Sink Nodes                                ||" << endl
        << "\t\t\t       || \t[5]  No. of Isolated Nodes                            ||" << endl
        << "\t\t\t       || \t[6]  No. of Bridge Edges                              ||" << endl
        << "\t\t\t       || \t[7]  No. of Articulation Nodes                        ||" << endl
        << "\t\t\t       || \t[8]  Shortest Path Length Distribution                ||" << endl
        << "\t\t\t       || \t[9]  Diameter of Graph                                ||" << endl
        << "\t\t\t       || \t[10] In-Degree Distribution Table                     ||" << endl
        << "\t\t\t       || \t[11] Out-degree Distribution table                    ||" << endl
        << "\t\t\t       || \t[12] Size of Largest Strongly Connected Component     ||" << endl
        << "\t\t\t       || \t[13] Size Distribution of All SCCs                    ||" << endl
        << "\t\t\t       || \t[14] Size of Largest Weakly Connected Component       ||" << endl
        << "\t\t\t       || \t[15] Size Distribution of All WCCs                    ||" << endl
        << "\t\t\t       || \t[16] EXIT                                             ||" << endl
        << "\t\t\t\t-------------------------************--------------------------" << endl;
    cout << endl<<endl<<endl;
    g1.insert();// directed graph insertion
    g1.undirectedinsert();//undirected graph insertion
    
    goto forward;
back:
    cout << endl << endl << endl;
    cout << "\n\n\t\t\t\t\t        Network Analysis Using Graphs        " << endl
        << "\t\t\t\t==============================================================" << endl
        << "\t\t\t\t                             MENU                             " << endl
        << "\t\t\t\t-------------------------************-------------------------" << endl
        << "\t\t\t       || \t[1]  No. of Nodes                                     ||" << endl
        << "\t\t\t       || \t[2]  No. of Edges                                     ||" << endl
        << "\t\t\t       || \t[3]  No. of Source Nodes                              ||" << endl
        << "\t\t\t       || \t[4]  No. of Sink Nodes                                ||" << endl
        << "\t\t\t       || \t[5]  No. of Isolated Nodes                            ||" << endl
        << "\t\t\t       || \t[6]  No. of Bridge Edges                              ||" << endl
        << "\t\t\t       || \t[7]  No. of Articulation Nodes                        ||" << endl
        << "\t\t\t       || \t[8]  Shortest Path Length Distribution                ||" << endl
        << "\t\t\t       || \t[9]  Diameter of Graph                                ||" << endl
        << "\t\t\t       || \t[10] In-Degree Distribution Table                     ||" << endl
        << "\t\t\t       || \t[11] Out-degree Distribution table                    ||" << endl
        << "\t\t\t       || \t[12] Size of Largest Strongly Connected Component     ||" << endl
        << "\t\t\t       || \t[13] Size Distribution of All SCCs                    ||" << endl
        << "\t\t\t       || \t[14] Size of Largest Weakly Connected Component       ||" << endl
        << "\t\t\t       || \t[15] Size Distribution of All WCCs                    ||" << endl
        << "\t\t\t       || \t[16] EXIT                                             ||" << endl
        << "\t\t\t\t-------------------------************--------------------------" << endl;
forward:
    cout << endl << endl << endl;
    cout << "\t\t\t\tEnter Your Choice:-->";
    cin >> choice;
    cout << endl << endl << endl;

    switch (choice)
    {
    case 1:
    {
        char y;
        cout << endl;
        cout << "\t\t\t\t"<<"The numeber of nodes are  : " << g1.noofnodesdirected() << endl;
        cout << endl;
        cout << endl;
        
        goto back;
        break;
    }
    case 2:
    {
        cout << endl;
    cout << "\t\t\t\t" << "The numeber of edges are  : " << g1.calculateedge() << endl;
    cout << endl;
    cout << endl;
    goto back;
    break;
    }
    case 3:
    {
        cout << endl;
        cout << "\t\t\t\t";
        g1.soursenode();
        cout << endl;
        cout << endl;
        goto back;
        break;
    }
    case 4:
    {
        cout << endl;
        cout << "\t\t\t\t";
        g1.sinknode();
        cout << endl;
        cout << endl;;
        goto back;
        break;
    }
    case 5:
    {
        cout << endl;
        cout << "\t\t\t\t";
        cout << "\t\t\t\t" <<"Total isolated nodes are "<< g1.isolated();
        cout << endl;
        cout << endl;
        goto back;
        break;
    }
    case 6:
    {
        cout << endl;
        cout << "\t\t\t\t" << "Total bridge edges are " << g1.bridging() << endl;
        cout << endl;
        cout << endl;
        goto back;
        break;
    }
    case 7:
    { 
        cout << endl;
   // cout << "\t\t\t\t";
        int counter = g1.articulationnodes();
        if (counter > 0) {
            cout << "\t\t\t\t" << " total articulation nodes are " << counter << endl;
        }
        else {
            cout << "\t\t\t\t" << "there are no articulation node in the graph" << endl;
        }
    
    cout << endl;
    goto back;
    break;
    }
    case 8:
    {
        cout << endl;
       // cout << "\t\t\t\t";
       g1.shotestpath();
        cout << endl;
        goto back;
        break;
    }
    case 9:
    {
        cout << endl;
       // cout << "\t\t\t\t";
        cout <<"\t\t\t\t"<< "Diameter of the graph is = " << g1.diameter();
        cout << endl;
        goto back;
        break;
    }
    case 10:
    {
        cout << endl;
        g1.indegreedistribution();
        cout << endl;
        goto back;
        break;
    }
    case 11:
    {
        cout << endl;
        g1.outdegreedistribution();
        cout << endl;
        goto back;
        break;
    }
    case 12:
    {
        cout << endl;
        cout << "\t\t\t\t"<<"the size of largest SCC = " <<g1.largestSCC();
        cout << endl;
        goto back;
        break;
    }
    case 13:
    {
        cout << endl;
        cout << "\t\t\t\t" << "the size distribution of SCC is" << endl;
        g1.sizedistributionofSCC();
        cout << endl;
        goto back;
        break;
    }
    case 14:
    {
        cout << endl;
        cout << "\t\t\t\t" << "the size of largest WCC = " << g1.largestWCC();
        cout << endl;
        goto back;
        break;
    }
    case 15:
    {
        cout << endl;
        cout << "\t\t\t\t" << "the size distribution of WCC is" << endl;
        g1.sizedistributionofWCC();
        cout << endl;
        goto back;
        break;
    }
    case 16:
       
        cout << endl;
        cout << "\t\t\t\t" << "TESTING END" << endl;
        return 0;

    }
    cout << endl;


Default:
    cout << "\t\t\t\t"<< "There is no such option in the Menu" << endl;
    cout << "\t\t\t\t"<< "Enter your choice again " << endl;
    goto back;


}



