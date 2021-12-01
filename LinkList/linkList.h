typedef struct linkList
{
	char* value;
	int times;
	struct linkList* nextNode;
	struct linkList* prevNode;
} linkList;

void addNode(linkList* endNode, char* value);
void insertNode(linkList* thisNode, char* value);
void delNode_byNode(linkList* thisNode);
void delNode_byValue(linkList* Node, char* value);
int findNode(linkList* head, char* value, linkList* pointOfValue);