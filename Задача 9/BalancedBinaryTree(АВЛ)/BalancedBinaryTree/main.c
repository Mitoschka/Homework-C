#include <stdio.h>
#include <stdlib.h>


typedef struct BinartTree
{
	int count;//число вхождений
	char *key, *item;//ключи и поле данных
	unsigned char height; //высота поддерева
	struct tree *left;//левый потомок
	struct tree *right;//правый потомок
} Node;

unsigned char height(Node* tNode) //получение высоты вершины
{//если вершины нет, ответ 0 иначе высота поддерева этой вершины
	return tNode ? tNode->height : 0;
}

int bfactor(Node* tNode)
{//разность высот между сыновьями
	return height(tNode->right) - height(tNode->left); //вычисление разницы
}

void fixheight(Node* tNode)
{//обновим высоту, если сбалансированность нарушена
	unsigned char hleft = height(tNode->left); //высота левого сына
	unsigned char hright = height(tNode->right); //высота правого сына
	//высота вершины - это высота сына с макс высотой плюс 1
	tNode->height = (hleft>hright ? hleft : hright) + 1; 
}

Node* rotateright(Node* tNode) //правый поворот вокруг nd
{
	Node* temp = tNode->left;
	tNode->left = temp->right;
	temp->right = tNode;
	fixheight(tNode);
	fixheight(tNode);
	return tNode;
}

Node* rotateleft(Node* tNode) //левый поворот вокруг nd
{
	Node* temp = tNode->right;
	tNode->right = temp->left;
	temp->left = tNode;
	fixheight(tNode);
	fixheight(temp);
	return temp;
}

Node* balance(Node* tNode) 
{//балансировка узла tNode древа
	fixheight(tNode);
	if (bfactor(tNode) == 2)
	{
		if (bfactor(tNode->right) < 0)
		{
			tNode->right = rotateright(tNode->right);
		}
		return rotateleft(tNode);
	}
	if (bfactor(tNode) == -2)
	{
		if (bfactor(tNode->left) > 0)
		{
			tNode->left = rotateleft(tNode->left);
		}
		return rotateright(tNode);
	}
	return tNode; //балансировка не нужна
}

Node *addNode(Node *tree, char *key, char *value) {
	//добавление узлов в древо
	int tSame;//для выбора ветви
	if (tree == NULL) 
	{//если дерева нет, то формируем корень
		tree = (Node *)malloc(sizeof(Node));//память под узел
		tree->key = strdup(key);//ключ
		tree->item = strdup(value);//поле данных
		tree->count = 1;
		//инициализация ветвей пустыми
		tree->left = tree->right = NULL;
	}
	//определяем ветвь для вставки данных
	//один и тот же ключ, заменим значение
	else if ((tSame = strcmp(key, tree->key)) == 0)
	{
		tree->count++;
		tree->item = strdup(value);//поле данных
	}
		
	//вставим в левую или правую ветви
	else if (tSame < 0)
	{
		tree->left = addNode(tree->left, key, value);
	}
	else
	{
		tree->right = addNode(tree->right, key, value);
	}
	return balance(tree);
}

Node* searchByKey(Node* tree, char *key) 
{//поиск узла по заданному ключу
	int tSame;
	Node *found = NULL;
	if (tree == NULL)
	{
		return tree;
	}
	//узел найден по ключу
	if ((tSame = strcmp(key, tree->key)) == 0)
	{
		found = tree;
		return found;
	}
	//выбор направления поиска по ключу
	else if (tSame < 0 && tree->left != NULL)
	{
		found = searchByKey(tree->left, key);
	}
	else if (tSame > 0 && tree->right != NULL)
	{
		found = searchByKey(tree->right, key);
	}

	//ключ не найден
	return found;
}

Node* findmin(Node* tNode) // поиск узла с минимальным ключом в дереве p 
{
	return tNode->left ? findmin(tNode->left) : tNode; //если есть левый сын, идем в него иначе ответ в этой вершине
}

Node* removemin(Node* tNode)
{//удаление узла с минимальным ключом из дерева p
	//если нет левого сына удалим эту вершину
	if (tNode->left == 0)
	{
		return tNode->right;
	}
	tNode->left = removemin(tNode->left); // иначе идем в левого сына
	return balance(tNode); //балансируем дерево
}

Node* removeByKey(Node* tree, char *key) 
{//удаление узла из древа по ключу key
	// если дерево пустое, уходим
	if (!tree)
	{
		return NULL;
	}
	int tSame = strcmp(key, tree->key);
	//если элемент меньше вершины идем в левого сына
	if (tSame < 0)
	{
		tree->left = removeByKey(tree->left, key);
	}
	//если элемент больше вершины, идем в правого сына
	else if (tSame > 0)
	{
		tree->right = removeByKey(tree->right, key);
	}
	else 
	{//мы пришли в вершину, которую нужно удалить		
		Node* ndLeft = tree->left;
		Node* ndRight = tree->right;
		free(tree);//физическое удаление вершины	
		printf("Запись удалена...\n");
		if (!ndRight)
		{ 
			return ndLeft; 
		}
		Node* min;
		min = findmin(ndRight);
		min->right = removemin(ndRight); //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
		min->left = ndLeft; //левый сын минимальной вершины - левый сын удаляемой
		return balance(min); //балансируем меньшую вершину
	}
	return balance(tree); //мы ничего не нашли, балансируем дерево
}

char *strToLower(char *value)
{//преобразование строки в нижний регистр
	const len = strlen(value);
	for (int i = 0; i<len; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'Z')
		{
			value[i] += 'z' - 'Z';
		}
		if (value[i] >= 'А' && value[i] <= 'Я')
		{
			value[i] += 'я' - 'Я';
		}
	}
	return value;
}

int menu()
{//реализация меню программы
	system("CLS");//очистка окна консоли
	printf("[MENU]\n");
	printf("1. Ввод значения\n");
	printf("2. Номер телефона по фамилии\n");
	printf("3. Проверка наличия заданного ключа\n");
	printf("4. Удаление записи\n");
	printf("5. Выход\n");
	printf("Input number: ");

	char *choose = (char *)malloc(100*sizeof(char));//выделение памяти для ключа;
	scanf("%s", choose);
	//возврат выбранного пункта меню
	if (choose < '0' && choose >'9')
	{
		free(choose);//освобожденипамяти
		return 0;
	}
	else
	{
		int nChouse = atoi(choose);
		free(choose);//освобожденипамяти
		return nChouse;
	}
}

int test()
{
	//тестирование функций
	
	//проверка на добавление
	Node *tree = NULL;
	char *key = "a";
	tree = addNode(tree, key, "value1");
	if (!tree)
	{
		return 0;
	}
	//проверка на удаление
	tree = removeByKey(tree, key);
	if (tree)
	{
		return 0;
	}

	//проверка на перевод символов в нижний регистр
	char *value = (char *)malloc(100 * sizeof(char));//выделение памяти для значения
	strcpy(value, "ЯГА");
	if (strcmp(strToLower(value), "яга") != 0)
	{
		return 0;
	}

	return 1;
}

int main()
{
	system("chcp 1251");
	
	if (!test())
	{
		printf("Тест не пройден...\n");
		system("pause");
	}
	
	Node *tree = NULL;//память под узел
	char *key = (char *)malloc(100*sizeof(char));//выделение памяти для ключа
	char *value = (char *)malloc(100*sizeof(char));//выделение памяти для значения



	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				system("cls");
				printf("ДОБАВЛЕНИЕ НОВОЙ ИНФОРМАЦИИ\n");
				printf("Введите фамилию: ");
				scanf("%s", key);
				key = strToLower(key);
				printf("Введите номер телефона: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("Запись внесена!\n");
				system("pause");
				break;
			}

			case 2:
			{
				system("cls");
				printf("ВЫВОД ИНФОРМАЦИИ ПО КЛЮЧУ\n");
				printf("Введите фамилию: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%s %s\n", found->key, found->item);
				}
				else
				{
					printf("Запись не найдена!\n");
				}
				system("pause");
				break;
			}
				

			case 3:
			{
				system("cls");
				printf("ПРОВЕРКА КЛЮЧА\n");
				printf("Введите фамилию для проверки ключа: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *searchKey = searchByKey(tree, key);
				if (searchKey)
				{
					printf("Данный ключ существует\n");
				}
				else
				{
					printf("Такого ключа нет!\n");
				}
				system("pause");				
				break;
			}
				
			case 4:
			{
				system("cls");
				printf("УДАЛЕНИЕ ДАННЫХ\n");
				printf("Введите фамилию для удаления: ");
				scanf("%s", key);
				key = strToLower(key);
				tree = removeByKey(tree, key);
				system("pause");
				break;
			}
				
			case 5:
			{
				loop = 0;
				break;
			}

			default:
			{
				printf("Неверный выбор...\n");
				break;
			}
				
		}//switch
	}//while 

	free(tree);
	free(value);
	free(key);
	
	return 0;
}