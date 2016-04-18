//icetea :::) :) :) :) : )
template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree( const BinarySearchTree & rhs);
	~BinarySearchTree();

	const Comparable & findMin( ) const; 
	const Comparable & findMax( ) const; 
	bool contains( const Comparable & x) const; 
	bool isEmpty() const; 
	void traverse() const; 

private:
	struct BinaryNode
	{
		Comparable element; 
		BinaryNode *left; 
		BinaryNode *right; 

		BinaryNode( const Comparable & theElement, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
			: element( theElement ), left(lt), right( rt ) { } 
	};

	BinaryNode *root; 
	void insert( const Comparable & x, BinaryNode * & t ) const; 
	void remove( const Comparable & x, BinaryNode * & t ) const; 
	BinaryNode * findMin( BinaryNode * t) const; 
	BinaryNode * findMax( BinaryNode * t) const; 
	bool contain( const Comparable & x, BinaryNode *t) const; 
	void clear( BinaryNode * & t); 
	void traverse( BinaryNode * t) const; 
	BinaryNode * clone( BinaryNode *t ) const;   
};

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const {
	return contains( x, root); 
}
template <typename Comparable>
bool BinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert( x , root ); 
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x)
{
	remove(x ,root); 
}
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinarySearchTree *t ) const
{
	if (t == nullptr)
		return false; 
	else if (x < t -> element);
		return contains(x, t -> left); 
	else if (t-> element < x)
		return contains( x, t->right); 
	else 
		return true;   // match
}

template <typename Comparable>
BinaryNode * BinarySearchTree<Comparable>::findMin( BinaryNode * t) const
{
	if (t == nullptr) 
		return nullptr; 
	if (t -> left == nullptr) 
		return t; 
	return findMin( t-> left); 
}

template <typename Comparable>
BinaryNode * BinarySearchTree<Comparable>::findMax( BinaryNode * t) const
{
	if (t == nullptr)
		return nullptr;
	if (t -> right == nullptr)
		return t; 
	return findMax(t -> right); 
}


template <typename Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x, BinaryNode * & t)
{
	if (t == nullptr) 
		t = new BinaryNode(x); 
	else if ( x < t -> element)
		insert( x, t -> left); 
	else if ( t -> element < x)
		insert(x, t-> right); 
	else; 
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x, BinaryNode * & t)
{
	if (t == nullptr)
		return; 
	if ( x < t -> element )
		remove( x, t -> left ); 
	else if ( t -> element < x) 
		remove( x, t -> right);
	else if ( t -> left != nullptr && t -> right != nullptr ){
		t -> element = findMin( t-> right) -> element; 
		remove( t -> element , t -> right );   
	} else {
		BinaryNode *oldNode = t; 
		t = ( t -> left != nullptr) ? t -> left : t -> right; 
		delete oldNode; 
	}
}



int main(){


	return 0; 
}