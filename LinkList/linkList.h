typedef struct linkList
{
	char* value;
	int times;
	struct linkList* nextNode;
	struct linkList* prevNode;
} linkList;

void addNode(linkList* endNode, char* value, int length);
void insertNode(linkList* thisNode, char* value);
void delNode_byNode(linkList* thisNode);
void delNode_byValue(linkList* Node, char* value);
int findNode(linkList* head, char* value, linkList* pointOfValue);
int findNode_noReturnPointer(const linkList* head, char* value);
void printList(const linkList* head);