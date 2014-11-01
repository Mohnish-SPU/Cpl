

void bfs(bst *tree)
{
	int *error = (int*)malloc(sizeof(int));
	Queue* q = queue_new();
	if(tree->root == NULL)
		return;
	else
	{
		enqueue(q,tree->root->data);
		while(queue_size(q)!=0)
		{
			int val = queue_front(q,error);
			node *temp = findNode(tree,val);
			if(temp->left!=NULL)
				enqueue(q,temp->left->data);
			if(temp->right!=NULL)
				enqueue(q,temp->right->data);
			print("%d ",val);
			
		}
	}
}
