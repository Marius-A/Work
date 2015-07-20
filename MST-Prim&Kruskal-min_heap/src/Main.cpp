#include "Kruskal.h"
#include "Prim.h"
#include "Graph.h"

int main()
{
	graph *G;
	char c, c1;
	FILE* f;
	FILE *g;
	do{
		system("cls");
		printf("\n ******************** MENIU *********************** \n");
		printf("|                                                   |\n");
		printf("|   [1].Test-mst                                    |\n");
		printf("|   [2].Apk                                         |\n");
		printf("|   [x].Pentru a iesi:                              |\n");
		printf("|                                                   |\n");
		printf(" **************************************************** \n");
		c = getch();
		switch (c) {
		case'1':system("cls");
			do {
				printf("\n---------------MENIU TESTARE MST--------------\n");
				int k, p;
				f = fopen("test_list.txt", "r");

					p=Prepair_Prim_MST_test(f);

				fclose(f);
				printf("-------------------------------------------------");
				f = fopen("test_list.txt", "r");

					k=Prepair_Kruskall_MST_test(f);

				fclose(f);
				if (k == p)
				{
					printf("\nSame MST!");
				}
				else
				{
					printf("\nDiffrent MST");
				}

				printf("\n Press [x] to return to the main menu.\n");
				c1 = getch();
				system("cls");
			} while (c1 != 'x');
			break;

		case'2':system("cls");
			do {
				printf("\n---------------MENIU Apk--------------\n");
				//graphGenerator("generated.txt");
				int k, p;

				g = fopen("generated.txt", "r");

					p=Prepair_Prim_MST_Graph_gen(g);

				fclose(g);

				printf("-------------------------------------------------");
				g = fopen("generated.txt", "r");

					k=Prepair_Kruskall_MST_Graph_gen(g);

				fclose(g);

				if (k == p)
				{
					printf("\nSame MST!");
				}
				else
				{
					printf("\nDiffrent MST");
				}
				printf("\n Press [x] to return to the main menu.\n");
				c1 = getch();
				system("cls");
			} while (c1 != 'x');
			break;
		}
	} while (c != 'x');
	system("pause");
	return 0;
}