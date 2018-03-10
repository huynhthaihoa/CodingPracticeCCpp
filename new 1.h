bool IsHeap(Tree T)
{
	if(!T)
		return true;
	return IsHeap(T->left) 
			&& IsHeap(T->right) 
			&& T->left->key <= T->key 
			&& T->right->key <= T->key;
}