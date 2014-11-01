




node* nodePost (int pre[], int* preIndex,int low, int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;
 
    // The first node in preorder traversal is root. So take the node at
    // preIndex from pre[] and make it root, and increment preIndex
    node* root = nodeInit ( pre[*preIndex] );
    *preIndex = *preIndex + 1;
 
    // If the current subarry has only one element, no need to recur
    if (low == high)
        return root;
 
    // Search for the first element greater than root
    int i;
    for ( i = low; i <= high; ++i )
        if ( pre[ i ] > root->data )
            break;
 
    // Use the index of element found in postorder to divide postorder array in
    // two parts. Left subtree and right subtree
    root->left = nodePost ( pre, preIndex, *preIndex, i - 1, size );
    root->right = nodePost ( pre, preIndex, i, high, size );
 
    return root;
}
