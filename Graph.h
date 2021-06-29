#pragma once
#include<iostream>
using namespace std;
#include"ADJlist.h"
#include<fstream>
#include<string>
#include <functional>
#include"Queue.h"
#include"Hash.h"
#include"stack.h"

class graph {
public:
	


	int sumofedge;
	int* sinkarray;
	int size;
	Adjlist* arr;
	Adjlist* undirectedarray;
	int* ptr;
	int* soursearray;
	int* isolatedarray;
	float degdistribution;
	int* copyoutdeg;
	//Adjlist* listforsecond;
	Adjlist* repeatinglist;
	int* bridgenodesarr;
	queue que;
	Hash hashingtable;
	Stack st;
	//Adjlist *
	Hash listforsecond;
	int* copyindeg;
	int** printoutdegreetable;
	int** printindegreetable;
	int count;
	int sumnodes;
	graph(int s) {
		sumnodes = 0;
		sumofedge = 0;
		count = 0;
		degdistribution = 0.0;

		size = s;
		copyoutdeg = new int[size];
		copyindeg = new int[size];
		for (int i = 0; i < size; i++) {
			copyoutdeg[i] = '\0';
			copyindeg[i] = '\0';
		}


		sinkarray = new int[size];
		arr = new Adjlist[size];
		undirectedarray = new Adjlist[size];
		ptr = new int[size];
		bridgenodesarr = new int[100];
		isolatedarray = new int[size];
		soursearray = new int[size];



		for (int i = 0; i < size; i++) {
			ptr[i] = '\0';
			soursearray[i] = '\0';
			sinkarray[i] = '\0';
			isolatedarray[i] = '\0';



		}


		//listforsecond = new Adjlist();
		repeatinglist = new Adjlist();
		hashingtable.setsize(size);
		listforsecond.setsize(size);
		


	}

	void addedge(int x, int y) {
		arr[x].cretelist(y);


	}


	/*void removeedge(int x, int y) {
		arr[x].delat(y);
	}*/
	int calculateedge() {
		int sumof = 0;
		for (int i = 0; i < size; i++) {
			node* temp4 = arr[i].head;
			while (temp4 != NULL) {
				sumofedge++;
				temp4 = temp4->next;
			}
		}
		sumof = sumofedge;
		sumofedge = 0;
		return sumof;
	}
	void print(int i) {

		arr[i].print();

	}

	void printundire(int i) {

		undirectedarray[i].printundi();

	}
	int noofnodesundirected()
	{
		int i = 0;
		int* reachable = new int[size];
		for (int k = 0; k < size; k++)
		{
			int n = undirectedarray[k].j;
			bool found = false;
			for (int l = 0; l < i; l++)
			{
				if (reachable[l] == n)
				{
					found = true;
				}
			}
			if (!found)
			{
				reachable[i] = n;
				i++;


			}
		}
		return i;
	}
	int noofnodesdirected()
	{
		int i = 0;
		int* reachable = new int[size];
		for (int k = 0; k < size; k++)
		{
			int n = undirectedarray[k].j;
			bool found = false;
			for (int l = 0; l < i; l++)
			{
				if (reachable[l] == n)
				{
					found = true;
				}
			}
			if (!found)
			{
				reachable[i] = n;
				i++;


			}
		}
		return i;
	}
	void insertarr(int index, int k) {
		arr[index].j = k;

	}

	void insertundirectedarr(int index, int k) {
		undirectedarray[index].j = k;

	}

	void outdegreecount(int index) {
		arr[index].outcount++;
	}
	void indegreecount(int index) {
		arr[index].incount++;
	}

	int VertexDegree(int v) {
		int count = 0;
		node* curr = arr[v].head;
		while (curr != NULL) {
			count++;
			curr = curr->next;
		}
		return count;
	}

	int noofedges() {

		for (int i = 0; i < size; i++) {
			print(i);
		}
		sumnodes = sum;
		sum = 0;
		return sumnodes;
	}

	void noofedgesinundire() {
		for (int i = 0; i < size; i++) {
			printundire(i);
		}
		cout << "Total no of edges =" << "  " << sum1 << endl;
	}
	void insert() {
		bool checkrep = true;
		int count = 0;
		int b = 1;
		ifstream obj("dry.txt");
		string str;
		int j = 0;
		int k = 0;
		string save = "";
		string save2 = "";

		int rep = 0;
		while (getline(obj, str)) {

			bool check = false;
			string nodeweightfrom = "", nodeweightto = "";
			int i = 0;
			if (count >= 4) {
				for (i = 0; str[i] != '\t'; i++) {
					nodeweightfrom += str[i];
				}


				i++;
				for (; str[i] != '\0'; i++) {
					nodeweightto += str[i];
				}
				if (nodeweightto == "") {

					int noweightfrom = stoi(nodeweightfrom);
					int lo;
					bool check11 = false;
					for (lo = 0; arr[lo].j != '\0'; lo++) {
						if (arr[lo].j == noweightfrom) {
							check11 = true;
							break;
						}
					}
					if (check11 == false) {
						arr[lo].j = noweightfrom;
					}
				}
				else {
					for (; str[i] != '\0'; i++) {
						nodeweightto += str[i];
					}

					int noweightfrom = stoi(nodeweightfrom);
					int noweightto = stoi(nodeweightto);


					listforsecond.pus(noweightto);  // list for indegree distribution....
					int ind = (noweightto % size);


					hashingtable.insertItem(noweightto); // repetition removal of second col

					int l;
					bool check1 = false;
					for (l = 0; arr[l].j != '\0'; l++) {
						if (arr[l].j == noweightfrom) {
							check1 = true;
							break;
						}
					}
					if (check1 == false) {
						arr[l].j = noweightfrom;
						if (arr[l].head == NULL) {
							arr[l].cretelist(noweightto);
							outdegreecount(l);
							int k;
							bool check4 = false;
							for (k = 0; arr[k].j != '\0'; k++) {
								if (arr[k].j == noweightto) {
									check4 = true;
									break;
								}
							}
							if (check4 == false) {
								arr[k].j = noweightto;
							}
						}
						else {
							bool check2 = false;
							node* temp1 = arr[l].head;
							while (temp1 != NULL) {
								if (temp1->data == noweightto) {
									check2 = true;
									break;
								}
								temp1 = temp1->next;
							}
							if (check2 == false) {
								arr[l].cretelist(noweightto);
								outdegreecount(l);
								int ko;
								bool check5 = false;
								for (ko = 0; arr[ko].j != '\0'; ko++) {
									if (arr[ko].j == noweightto) {
										check5 = true;
										break;
									}
								}
								if (check5 == false) {
									arr[ko].j = noweightto;
								}
							}
							else {
								int ju;
								bool check7 = false;
								for (ju = 0; arr[ju].j != '\0'; j++) {
									if (arr[ju].j == noweightto) {
										check7 = true;
										break;
									}
								}
								if (check7 == false) {
									arr[ju].j = noweightto;
								}
							}
						}
					}
					else {
						if (arr[l].head == NULL) {
							arr[l].cretelist(noweightto);
							outdegreecount(l);
							bool check6 = false;
							int ji;
							for (ji = 0; arr[ji].j != '\0'; ji++) {
								if (arr[ji].j == noweightto) {
									check6 = true;
									break;
								}
							}
							if (check6 == false) {
								arr[ji].j = noweightto;
							}
						}
						else {
							bool check2 = false;
							node* temp1 = arr[l].head;
							while (temp1 != NULL) {
								if (temp1->data == noweightto) {
									check2 = true;
									break;
								}
								temp1 = temp1->next;
							}
							if (check2 == false) {
								arr[l].cretelist(noweightto);
								outdegreecount(l);
								int ko;
								bool check5 = false;
								for (ko = 0; arr[ko].j != '\0'; ko++) {
									if (arr[ko].j == noweightto) {
										check5 = true;
										break;
									}
								}
								if (check5 == false) {
									arr[ko].j = noweightto;
								}
							}
							else {
								bool check10 = false;
								int ky;
								for (ky = 0; arr[ky].j != '\0'; ky++) {
									if (arr[ky].j == noweightto) {
										check10 = true;
										break;
									}
								}
								if (check10 == false) {
									arr[ky].j = noweightto;
								}
							}
						}
					}
				}
			}
			count++;
		}
	}

	void undirectedinsert() {
		string save = "";
		string save2 = "";
		int count = 0;

		ifstream obj("dry.txt");
		string str = "";
		int first, second;
		while (getline(obj, str)) {
			bool checkrepetition = false;
			bool check = false;
			string nodeweightfrom = "", nodeweightto = "";
			int i = 0;
			if (count >= 4) {
				for (i = 0; str[i] != '\t'; i++) {
					nodeweightfrom += str[i];
				}
				i++;
				bool null = false;
				if (str[i] == '\0') {
					null = true;
				}
				if (null == true) {
					bool helo = false;
					int noweightfrom = stoi(nodeweightfrom);
					int ki;
					for (ki = 0; undirectedarray[ki].j != '\0'; ki++) {
						if (undirectedarray[ki].j == noweightfrom) {
							helo = true;
						}
					}
					if (helo == false) {
						undirectedarray[ki].j = noweightfrom;
					}
				}
				else {
					for (; str[i] != '\0'; i++) {
						nodeweightto += str[i];
					}
					int noweightfrom = stoi(nodeweightfrom);
					int noweightto = stoi(nodeweightto);

					int j = 0;
					bool check = false;
					for (j = 0; undirectedarray[j].j != '\0'; j++) {
						if (undirectedarray[j].j == noweightfrom) {
							check = true;
						}
					}
					if (check == false) {
						undirectedarray[j].j = noweightfrom;
						if (undirectedarray[j].head == NULL) {
							undirectedarray[j].cretelist(noweightto);
							int l;
							bool checkr = false;
							for (l = 0; undirectedarray[l].j != '\0'; l++) {
								if (undirectedarray[l].j == noweightto) {
									checkr = true;
								}
							}
							if (checkr == false) {
								undirectedarray[l].j = noweightto;
								if (undirectedarray[l].head == NULL) {
									undirectedarray[l].cretelist(noweightfrom);
								}

							}
							else {
								int ki;
								for (ki = 0; undirectedarray[ki].j != '\0'; ki++) {
									if (undirectedarray[ki].j == noweightto) {
										break;
									}
								}
								if (undirectedarray[ki].head == NULL) {
									undirectedarray[ki].cretelist(noweightfrom);
								}
								else {
									bool checking = false;
									node* temp6 = undirectedarray[ki].head;
									while (temp6 != NULL) {
										if (temp6->data == noweightfrom) {
											checking = true;
											break;
										}
										temp6 = temp6->next;
									}
									if (checking == false) {
										undirectedarray[ki].cretelist(noweightfrom);
									}
								}
							}
						}
					}
					//================================================
					else {
						int f;
						bool checkn = false;
						for (f = 0; undirectedarray[f].j != '\0'; f++) {
							if (undirectedarray[f].j == noweightfrom) {
								break;
							}
						}
						if (undirectedarray[f].head == NULL) {
							bool chk6 = false;
							undirectedarray[f].cretelist(noweightto);
							int lo;
							for (lo = 0; undirectedarray[lo].j != '\0'; lo++) {
								if (undirectedarray[lo].j == noweightto) {
									chk6 = true;
								}
							}
							if (chk6 == false) {
								undirectedarray[lo].j = noweightto;
								bool chk7 = false;
								if (undirectedarray[lo].head == NULL) {
									undirectedarray[lo].cretelist(noweightfrom);
								}
								/*	else {
										node* temp5 = undirectedarray[lo].head;
										while (temp5 != NULL) {
											if (temp5->data == noweightfrom) {
												chk7 = true;
												break;
											}
											temp5 = temp5->next;
										}
										if (chk7 == false) {
											undirectedarray[lo].cretelist(noweightfrom);
										}
									}*/
							}
							else {
								int k;
								bool checking30 = false;
								for (k = 0; undirectedarray[k].j != '\0'; k++) {
									if (undirectedarray[k].j == noweightto) {
										checking30 = true;
										break;
									}
								}
								if (checking30 == false) {
									undirectedarray[k].j = noweightto;
									undirectedarray[k].cretelist(noweightfrom);
								}
								else {
									bool checking50 = false;
									node* temp70 = undirectedarray[k].head;
									while (temp70 != NULL) {
										if (temp70->data == noweightfrom) {
											checking50 = true;
										}
										temp70 = temp70->next;
									}
									if (checking50 == false) {
										undirectedarray[k].cretelist(noweightfrom);
									}
								}

							}
						}
						else {
							bool chek5 = false;
							node* temp3 = undirectedarray[f].head;
							while (temp3 != NULL) {
								if (temp3->data == noweightto) {
									chek5 = true;
									break;
								}
								temp3 = temp3->next;
							}
							if (chek5 == false) {
								undirectedarray[f].cretelist(noweightto);
								bool chk7 = false;
								int lu;
								for (lu = 0; undirectedarray[lu].j != '\0'; lu++) {

									if (undirectedarray[lu].j == noweightto) {
										chk7 = true;

									}
								}
								if (chk7 == false) {
									undirectedarray[lu].j = noweightto;
									if (undirectedarray[lu].head == NULL) {
										undirectedarray[lu].cretelist(noweightfrom);

									}
									/*	else {
											node* tem6 = undirectedarray[lu].head;
											bool chk9 = false;
											while (tem6 != NULL) {
												if (tem6->data == noweightfrom) {
													chk9 = true;
													break;
												}
												tem6 = tem6->next;
											}
											if (chk9 == false) {
												undirectedarray[lu].cretelist(noweightfrom);
											}
										}*/
								}
								//3
								else {
									int jo;
									bool waq = false;
									for (jo = 0; undirectedarray[jo].j != '\0'; jo++) {
										if (undirectedarray[jo].j == noweightto) {
											break;
										}
									}
									if (undirectedarray[jo].head == NULL) {
										undirectedarray[jo].cretelist(noweightfrom);
									}
									else {
										bool han = false;
										node* temp10 = undirectedarray[jo].head;
										while (temp10 != NULL) {
											if (temp10->data == noweightfrom) {
												han = true;
												break;
											}
											temp10 = temp10->next;
										}
										if (han == false) {
											undirectedarray[jo].cretelist(noweightfrom);
										}
									}


								}
							}
						}

					}
				}
			}
			count++;
		}
		/*for (int i = 0; i < size; i++) {
			node* temp5 = undirectedarray[i].head;
			cout << undirectedarray[i].j << " ";
			while (temp5 != NULL) {
				cout << temp5->data << " ";
				temp5 = temp5->next;
			}
			cout << endl;
		}*/



	}


	void soursenode() {
		bool check = false;
		int totalsoursenodes = 0;
		int k = 0;
		for (int i = 0; i < size; i++) {
			check = false;
			int y = arr[i].j;
			int ind = y % size;
			node* curr = hashingtable.table[ind].head;

			while (curr != NULL) {

				if (curr->data == y) {
					check = true;
					goto abc;
				}

				curr = curr->next;
			}

		abc:
			if (check == false) {
				totalsoursenodes++;
				soursearray[k] = y;
				//cout << y << endl;

				k++;
			}
		}


		if (totalsoursenodes == 0) {
			cout << "In this graph no node is source node" << endl;
		}
		else {
			cout << "The total source nodes are " << totalsoursenodes << " ";
			cout << "Which are" << " ";
			for (int o = 0; soursearray[o] != '\0'; o++) {
				cout << soursearray[o] << " ";
			}
			cout << endl;
		}

	}

	void sinknode() {

		int k = 0;
		int sinkcount = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].head == NULL) {
				sinkarray[k] = arr[i].j;
				sinkcount++;
				k++;
			}
		}
		if (sinkarray[0] == '\0') {
			cout << "There are no sink nodes in graph" << endl;
		}
		else {
			cout << "There are :" << " " << sinkcount << " Sink nodes ";
			cout << "Which is" << " ";
			for (int i = 0; sinkarray[i] != '\0'; i++) {
				cout << sinkarray[i] << " ";
			}

		}

	}

	int isolated() {
		int* isolatedarr = new int[size];
		for (int l = 0; l < size; l++) {
			isolatedarr[l] = '\0';
		}
		sinknode();
		cout << endl;
		cout << "\t\t\t\t" << "And ";
		soursenode();
		int count = 0;
		int k = 0;
		for (int i = 0; sinkarray[i] != '\0'; i++) {
			for (int j = 0; soursearray[j] != '\0'; j++) {
				if (sinkarray[i] == soursearray[j]) {
					isolatedarr[k] = sinkarray[i];
					k++;
					count++;
				}
			}
		}
		if (count == 0) {
			cout << "\t\t\t\t" << "There are no common nodes in sink and source arrays so the" << endl;
		}
		else {
			for (int i = 0; isolatedarr[i] != '\0'; i++) {
				cout << "\t\t\t\t" << "Isolated nodes are :" << isolatedarr[i] << " ";
			}
			cout << endl;
		}
		return count;
	}


	void outdegreedistribution() {
		int counter = 0;

		for (int i = 0; i < size; i++) {
			copyoutdeg[i] = arr[i].outcount;

		}
		for (int i = 1; i < size; ++i)
		{

			if (copyoutdeg[0] < copyoutdeg[i])
				copyoutdeg[0] = copyoutdeg[i];
		}
		printoutdegreetable = new int* [copyoutdeg[0]];
		for (int i = 0; i <= copyoutdeg[0]; i++) {
			printoutdegreetable[i] = new int[1];
		}
		for (int i = 0; i <= copyoutdeg[0]; i++) {

			for (int j = 0; j < 1; j++) {
				printoutdegreetable[i][j] = 0;
			}

		}
		int count = 0;

		for (int i = 0; i < size; i++) {

			count = arr[i].outcount;
			printoutdegreetable[count][0]++;
		}
		int sum = 0;

		for (int i = 0; i <= copyoutdeg[0]; i++) {
			cout << "\t\t\t\t" << "------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t" << "The nodes which have " << i << " Outdegree Distribution is " << "\t" << " : " << (printoutdegreetable[i][0]) * 1.0 / size << endl;
		}

	}

	void indegreedistribution() {
		int k = 0;
		int counter = 0;
		for (int i = 0; i < size; i++) {
			int index = arr[i].j % size;
			node* curr = listforsecond.table[index].head;
			while (curr != NULL) {
				if (arr[i].j == curr->data) {
					indegreecount(i);
				}
				curr = curr->next;
			}

		}
		for (int i = 0; i < size; i++) {
			copyindeg[i] = arr[i].incount;

		}
		for (int i = 1; i < size; ++i)
		{

			if (copyindeg[0] < copyindeg[i])
				copyindeg[0] = copyindeg[i];
		}
		printindegreetable = new int* [copyindeg[0]];
		for (int i = 0; i <= copyindeg[0]; i++) {
			printindegreetable[i] = new int[1];
		}
		for (int i = 0; i <= copyindeg[0]; i++) {

			for (int j = 0; j < 1; j++) {
				printindegreetable[i][j] = 0;
			}

		}
		int count = 0;

		for (int i = 0; i < size; i++) {

			count = arr[i].incount;
			printindegreetable[count][0]++;
		}
		int sum = 0;

		for (int i = 0; i <= copyindeg[0]; i++) {
			cout << "\t\t\t\t" << "------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t" << "The nodes which have " << i << "\t" << "INDEGREE Distribution is " << " : " << (printindegreetable[i][0]) * 1.0 / size << endl;
		}

		for (int i = 0; i < size; i++) {
			arr[i].incount = '\0';

		}

	}

	int BFSundirectedtraversal(int startNode) {
		bool* checkarr = new bool[size];
		for (int i = 0; i < size; i++) {
			checkarr[i] = false;
		}
		int totalbfsundirected;
		totalbfsundirected = 0;
		int i = 0;
		for (i = 0; undirectedarray[i].j != startNode; i++) {

		}
		checkarr[i] = true;
		que.enQueue(undirectedarray[i].j);
		while (que.empty() != true) {
			int save = que.deQueue();

			//cout << save << " ";
			totalbfsundirected++;

			int l;
			for (l = 0; undirectedarray[l].j != save; l++) {

			}
			if (undirectedarray[l].j == save && l < size) {
				node* temp = undirectedarray[l].head;
				while (temp != NULL) {
					int savelink = temp->data;
					int k;
					for (k = 0; (undirectedarray[k].j != savelink) && k < size; k++) {

					}
					if (savelink == undirectedarray[k].j) {
						if (checkarr[k] == false) {
							checkarr[k] = true;
							que.enQueue(savelink);

						}
					}
					else {
						/*cout << savelink << " ";*/
						totalbfsundirected++;


					}

					temp = temp->next;
				}
			}


		}
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (checkarr[i] == true) {
				count++;
			}
		}

		//cout <<"undire"<< totalbfs++ << endl;
		return totalbfsundirected;

	}


	int* BFS(int startNode)
	{
		int* reachable;
		int i = 0;
		que.enQueue(startNode);
		reachable = new int[size];
		for (int i = 0; i < size; i++) {
			reachable[i] = '\0';
		}
		reachable[i] = startNode;
		i++;
		while (!que.empty())
		{
			int x = que.deQueue();
			int j;
			for (j = 0; j < size; j++) {
				if (arr[j].j == x) {
					break;
				}
			}
			if (arr[j].j == x) {
				//			cout << "j:" << j << " arr[j]:" << arr[j].j << endl;
				node* temp1 = arr[j].head;
				while (temp1 != NULL)
				{
					//				cout << "tdata:" << temp1->data << endl;
					int num = temp1->data;
					bool found = false;
					//				cout << "i: " << i << endl;
					for (int k = 0; k < i; k++)
					{

						if (num == reachable[k])
						{
							found = true;
						}
					}
					if (!found)
					{
						que.enQueue(num);
						reachable[i] = num;
						i++;
					}
					temp1 = temp1->next;
				}
			}


		}
		return reachable;
	}
	int* BFSundirected(int startNode)
	{
		int* reachable;
		int i = 0;
		que.enQueue(startNode);
		reachable = new int[size];
		for (int i = 0; i < size; i++) {
			reachable[i] = '\0';
		}
		reachable[i] = startNode;
		i++;
		while (!que.empty())
		{
			int x = que.deQueue();
			int j;
			for (j = 0; j < size; j++) {
				if (undirectedarray[j].j == x) {
					break;
				}
			}
			if (undirectedarray[j].j == x) {
				//			cout << "j:" << j << " arr[j]:" << arr[j].j << endl;
				node* temp1 = undirectedarray[j].head;
				while (temp1 != NULL)
				{
					//				cout << "tdata:" << temp1->data << endl;
					int num = temp1->data;
					bool found = false;
					//				cout << "i: " << i << endl;
					for (int k = 0; k < i; k++)
					{

						if (num == reachable[k])
						{
							found = true;
						}
					}
					if (!found)
					{
						que.enQueue(num);
						reachable[i] = num;
						i++;
					}
					temp1 = temp1->next;
				}
			}


		}
		return reachable;
	}
	

	int DFSundirected(int startNode)
	{
		int* reachable;
		int i = 0;
		st.push(startNode);
		reachable = new int[size];
		for (int i = 0; i < size; i++) {
			reachable[i] = '\0';
		}
		reachable[i] = startNode;
		i++;
		while (!st.isempty())
		{
			int x = st.pop();
			int j;
			for (j = 0; j < size; j++) {
				if (undirectedarray[j].j == x) {
					break;
				}
			}
			if (undirectedarray[j].j == x) {
				//			cout << "j:" << j << " arr[j]:" << arr[j].j << endl;
				node* temp1 = undirectedarray[j].head;
				while (temp1 != NULL)
				{
					//				cout << "tdata:" << temp1->data << endl;
					int num = temp1->data;
					bool found = false;
					//				cout << "i: " << i << endl;
					for (int k = 0; k < i; k++)
					{

						if (num == reachable[k])
						{
							found = true;
						}
					}
					if (!found)
					{
						st.push(num);
						reachable[i] = num;
						i++;
					}
					temp1 = temp1->next;
				}
			}


		}
		return i;
	}

	

	


	int bridging() {
		int fullBFS;
		int count = 0;

		int i;
		int j = 1;

		for (int i = 0; i < size; i++) {
				cout <<"time check::  " <<i << endl;
			fullBFS = BFSundirectedtraversal(undirectedarray[i].j);
			node* curr = undirectedarray[i].head;
			node* ptr = undirectedarray[i].head;
			node* mid = undirectedarray[i].head;

			while (curr != NULL) {
				if (curr == undirectedarray[i].head && curr->next != NULL) {

					undirectedarray[i].head = undirectedarray[i].head->next;

					int ans;
					ans = BFSundirectedtraversal(undirectedarray[i].j);
					//cout << ans << endl;
					if (ans != fullBFS) {

						count++;
						cout << "\t\t\t\t" << "Bridge " << undirectedarray[i].j << "  " << curr->data << "  " << endl;
					}
					undirectedarray[i].head = ptr;

				}
				else if (curr == undirectedarray[i].head && curr->next == NULL) {

					undirectedarray[i].head = NULL;
					int ans;
					ans = BFSundirectedtraversal(undirectedarray[i].j);

					if (ans != fullBFS) {
						count++;

						cout << "\t\t\t\t" << "Bridge " << undirectedarray[i].j << "  " << curr->data << "  " << endl;
					}
					undirectedarray[i].head = ptr;
				}
				else if (curr != undirectedarray[i].head && curr->next != NULL) {

					mid->next = curr->next;
					curr->next = NULL;
					int ans;
					ans = BFSundirectedtraversal(undirectedarray[i].j);

					if (ans != fullBFS) {
						count++;

						cout << "\t\t\t\t" << "Bridge " << undirectedarray[i].j << "  " << curr->data << "  " << endl;
					}
					curr->next = mid->next;
					mid->next = curr;

				}
				else if (curr->next == NULL) {

					mid->next = NULL;
					int ans;
					ans = BFSundirectedtraversal(undirectedarray[i].j);

					if (ans != fullBFS) {
						count++;

						cout << "\t\t\t\t" << "Bridge " << undirectedarray[i].j << "  " << curr->data << "  " << endl;
					}
					mid->next = curr;
				}
				mid = curr;
				curr = curr->next;
			}
		}
		cout << endl;
		count = count / 2;
		return count;
	}

	int* IN(int startnode) {
		int k = 0;
		int* inarr = new int[size];
		for (int i = 0; i < size; i++) {
			inarr[i] = '\0';
		}
		int i;

		for (int i = 0; i < size; i++) {
			bool checki = false;
			int* visited = BFS(arr[i].j);
			for (int i = 0; i < size; i++) {
				if (visited[i] == startnode) {
					checki = true;
					break;
				}
			}
			if (checki == true) {
				inarr[k] = arr[i].j;
				k++;
			}

		}

		return inarr;
	}
	int* out(int startnode) {
		int* outarr = new int[size];
		outarr = BFS(startnode);
		return outarr;
	}

	int* SCC() {

		int** SCCarr;

		SCCarr = new int* [size];
		for (int i = 0; i < size; i++) {
			SCCarr[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				SCCarr[i][j] = '\0';
			}

		}
		int* countSSC = new int[size];
		for (int i = 0; i < size; i++) {
			countSSC[i] = 0;
		}
		int count = 0;
		int count1 = 0;
		int k = 0;
		for (int i = 0; i < size; i++) {
			cout <<"time check  "<< i << endl;
			int* in = IN(arr[i].j);
			int* outer = out(arr[i].j);
			int* Sarr = intersection(in, outer);
			for (int y = 0; y < size; y++) {
				if (Sarr[y] != '\0') {
					SCCarr[i][y] = Sarr[y];
					countSSC[i]++;
				}
				else {
					break;
				}
			}


		}
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << " " << SCCarr[i][j] << " ";
			}
			cout << endl;
		}*/
		return countSSC;
	}

	int* intersection(int* first, int* second) {
		int* final = new int[size];
		for (int i = 0; i < size; i++) {
			final[i] = '\0';
		}
		int k = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (first[i] == second[j]) {
					final[k] = first[i];
					k++;
					break;
				}
			}
		}
		return final;
	}

	int largestSCC() {
		int* counter = SCC();
		int largest = 0;
		for (int i = 1; i < size; ++i)
		{
			if (counter[0] < counter[i])
				counter[0] = counter[i];
		}
		largest = counter[0];
		return largest;
	}

	int* WCC() {
		int** WCCarr = new int* [size];
		for (int i = 0; i < size; i++) {
			WCCarr[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				WCCarr[i][j] = '\0';
			}
		}
		int* counter = new int[size];
		for (int i = 0; i < size; i++) {
			counter[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			bool checki = false;
			cout << "time check  " << i << endl;
			int* visited = BFSundirected(undirectedarray[i].j);
			for (int j = 0; j < size; j++) {
				if (visited[j] != '\0') {
					WCCarr[i][j] = visited[j];
					counter[i]++;
				}
				else {
					break;
				}
			}
		}
		return counter;
	}
	int largestSSC() {
		int* counter = SCC();
		int largest = 0;
		for (int i = 1; i < size; ++i)
		{
			
			if (counter[0] < counter[i])
				counter[0] = counter[i];
		}
		largest = counter[0];
		return largest;
	}
	void sizedistributionofSCC() {
		int* counter = SCC();
		int** sizedSCC = new int* [size];
		for (int i = 0; i < size; i++) {
			sizedSCC[i] = new int[1];
		}
		for (int i = 0; i < size; i++) {
			sizedSCC[i][0] = counter[i];
		}
		for (int i = 0; i < size; i++) {
			cout << "\t\t\t\t" << "for " << i + 1 << " SSC Size is:" << sizedSCC[i][0] << endl;
		}

	}
	void sizedistributionofWCC() {
		int* counter = WCC();
		int** sizedWCC = new int* [size];
		for (int i = 0; i < size; i++) {
			sizedWCC[i] = new int[1];
		}
		for (int i = 0; i < size; i++) {
			sizedWCC[i][0] = counter[i];
		}
		int largest = 0;
		for (int i = 1; i < size; ++i)
		{
			// Change < to > if you want to find the smallest element
			if (counter[0] < counter[i])
				counter[0] = counter[i];
		}
		largest = counter[0];
		
		for (int i = 0; i < size; i++) {
			cout << "\t\t\t\t" << "for " << i + 1 << " WCC Size is:" << sizedWCC[i][0] << endl;
		}

	}

	int largestWCC() {
		int* counter = WCC();
		int largest = 0;

		for (int i = 1; i < size; ++i)
		{
			// Change < to > if you want to find the smallest element
			if (counter[0] < counter[i])
				counter[0] = counter[i];
		}
		largest = counter[0];
		return largest;
	}


	int articulationnodes() {

		int counter1 = 0;
		
		for (int k = 0; k < size; k++) {
			int BFSFULL = DFSundirected(undirectedarray[k].j);
			int* arrayrestore = new int[size];
			for (int j = 0; j < size; j++) {
				arrayrestore[j] = '\0';
			}
			int value;
			int indexing;
			if (undirectedarray[k].head != NULL) {
				for (int lu = 0; undirectedarray[lu].j != '\0'; lu++) {
					if (undirectedarray[k].head->data == undirectedarray[lu].j) {
						indexing = lu;
						break;
					}
				}
			}
			else {
				for (int lu = 0; undirectedarray[lu].j != '\0'; lu++) {
					if (undirectedarray[k].j == undirectedarray[lu].j) {
						indexing = lu;
						break;
					}
				}
			}
			int l = 0;
			int arrayelement = undirectedarray[k].j;
			node* traverse = undirectedarray[k].head;
			while (traverse != NULL) {
				bool chek = false;
				int i;
				for (i = 0; undirectedarray[i].j != '\0'; i++) {
					if (undirectedarray[i].j == traverse->data) {
						chek = true;
						break;
					}
				}
				if (chek == true) {
					node* temp3 = undirectedarray[i].head;
					bool checkinlist = false;
					while (temp3 != NULL) {
						if (temp3->data == arrayelement) {
							checkinlist = true;
						}
						temp3 = temp3->next;
					}
					if (checkinlist == true) {
						node* curr = undirectedarray[i].head;
						node* ptr = undirectedarray[i].head;
						node* mid = undirectedarray[i].head;

						while (curr != NULL) {
							if (curr->data == arrayelement) {
								if (curr == undirectedarray[i].head && curr->next != NULL) {

									undirectedarray[i].head = undirectedarray[i].head->next;
									arrayrestore[l] = i;
									l++;
									//undirectedarray[i].head = ptr;//retore
									break;
								}
								else if (curr == undirectedarray[i].head && curr->next == NULL) {

									undirectedarray[i].head = NULL;
									arrayrestore[l] = i;
									l++;
									break;
									//undirectedarray[i].head = ptr;//retore
								}
								else if (curr != undirectedarray[i].head && curr->next != NULL) {//mid

									mid->next = curr->next;
									curr->next = NULL;
									arrayrestore[l] = i;
									l++;
									break;

									/*curr->next = mid->next;
									mid->next = curr;*///retore

								}
								else if (curr->next == NULL) {

									mid->next = NULL;
									arrayrestore[l] = i;
									l++;
									break;

									//mid->next = curr;//retore
								}
							}

							mid = curr;
							curr = curr->next;
						}
					}
				}
				traverse = traverse->next;
			}
			node* dellist = undirectedarray[k].head;
			undirectedarray[k].head = NULL;
			undirectedarray[k].j = '\0';
			int answer;
			//answer = BFSundirectedtraversal(indexing);
			if (k < size - 1) {
				answer = DFSundirected(undirectedarray[k + 1].j);
			}
			else {
				answer = DFSundirected(undirectedarray[k - 1].j);
			}

			if (answer < BFSFULL - 1) {
				cout << "INDEX FOR TIME " << k << endl;
				//cout << "\t\t\t\t" << arrayelement << " " << "Articluation node" << endl;
				counter1++;
			}
			undirectedarray[k].j = arrayelement;//restore
			undirectedarray[k].head = dellist;
			for (int lo = 0; arrayrestore[lo] != '\0'; lo++) {
				undirectedarray[arrayrestore[lo]].cretelist(arrayelement);
			}
		}
		return counter1;
	}

 void shotestpath() {
		int ko = 0;
		int* shortdist = new int[size];

		for (int lo = 0; lo < size; lo++) {
			cout << "for time:: " << lo << endl;
			bool* checkarr = new bool[size];
			for (int i = 0; i < size; i++) {
				checkarr[i] = false;
			}

			int* distance1 = new int[size];
			for (int i = 0; i < size; i++) {
				distance1[i] = 0;
			}


			checkarr[lo] = true;
			que.enQueue(undirectedarray[lo].j);
			while (que.empty() != true) {
				int save = que.deQueue();

				//cout << save << " ";


				int l;
				for (l = 0; undirectedarray[l].j != save; l++) {

				}
				if (undirectedarray[l].j == save && l < size) {
					node* temp = undirectedarray[l].head;
					while (temp != NULL) {

						int savelink = temp->data;
						int k;
						for (k = 0; (undirectedarray[k].j != savelink) && k < size; k++) {

						}
						if (savelink == undirectedarray[k].j) {
							if (checkarr[k] == false) {
								checkarr[k] = true;
								int plus = distance1[l];

								distance1[k] = plus + 1;
								que.enQueue(savelink);

							}
						}


						temp = temp->next;
					}
				}


			}
			int temp = distance1[0];
			for (int i = 0; i < size; i++) {
				if (temp < distance1[i]) {
					temp = distance1[i];
				}
			}
			shortdist[lo] = temp;


		}
		int temp2 = shortdist[0];
		for (int g = 0; g < size; g++) {
			for (int i = 0; i < size; i++) {
				if (temp2 < shortdist[i]) {
					temp2 = shortdist[i];
				}
			}
		}
		
		int **shortlength=new int*[temp2+1];
		for (int h = 0; h < temp2+1; h++) {
			shortlength[h] = new int[1];
		}
		for (int h = 0; h < temp2+1; h++) {
			shortlength[h][0] = 0;
		}
		for (int h = 0; h < size; h++) {
			shortlength[shortdist[h]][0]++;
		}

		for (int h = 1; h < temp2+1; h++) {
			  cout << "\t\t\t\t"<<"Length distribution of\t " << h << " :: "<<"\t"<< shortlength[h][0]<<" " <<"(NODES)"<< endl;
		}

		
	}

 int diameter() {
	 int ko = 0;
	 int* shortdist = new int[size];

	 for (int lo = 0; lo < size; lo++) {
		 cout << "for time:: " << lo << endl;
		 bool* checkarr = new bool[size];
		 for (int i = 0; i < size; i++) {
			 checkarr[i] = false;
		 }

		 int* distance1 = new int[size];
		 for (int i = 0; i < size; i++) {
			 distance1[i] = 0;
		 }


		 checkarr[lo] = true;
		 que.enQueue(undirectedarray[lo].j);
		 while (que.empty() != true) {
			 int save = que.deQueue();

			 //cout << save << " ";


			 int l;
			 for (l = 0; undirectedarray[l].j != save; l++) {

			 }
			 if (undirectedarray[l].j == save && l < size) {
				 node* temp = undirectedarray[l].head;
				 while (temp != NULL) {

					 int savelink = temp->data;
					 int k;
					 for (k = 0; (undirectedarray[k].j != savelink) && k < size; k++) {

					 }
					 if (savelink == undirectedarray[k].j) {
						 if (checkarr[k] == false) {
							 checkarr[k] = true;
							 int plus = distance1[l];

							 distance1[k] = plus + 1;
							 que.enQueue(savelink);

						 }
					 }


					 temp = temp->next;
				 }
			 }


		 }
		 int temp = distance1[0];
		 for (int i = 0; i < size; i++) {
			 if (temp < distance1[i]) {
				 temp = distance1[i];
			 }
		 }
		 shortdist[lo] = temp;


	 }
	 int temp2 = shortdist[0];
	 for (int g = 0; g < size; g++) {
		 for (int i = 0; i < size; i++) {
			 if (temp2 < shortdist[i]) {
				 temp2 = shortdist[i];
			 }
		 }
	 }

	 return temp2;
 }
	
};