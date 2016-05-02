
/*! As Reference  

	C++ : BidirectionIterator, ForwardIterator, InputIterator  (read)
		  OutputIterator 									   (write)	
	reference: 
		https://github.com/Mikko-Finell/json/blob/master/src/json.hpp

    @brief a mutable random access iterator for the @ref basic_json class
    @requirement The class satisfies the following concept requirements:
    - [RandomAccessIterator](http://en.cppreference.com/w/cpp/concept/RandomAccessIterator):
      The iterator that can be moved to point (forward and backward) to any
      element in constant time.
    - [OutputIterator](http://en.cppreference.com/w/cpp/concept/OutputIterator):
      It is possible to write to the pointed-to element.
    @since version 1.0.0
*/
    class iterator : public const_iterator
    {
      public:
        using base_iterator = const_iterator;
        using pointer = typename basic_json::pointer;
        using reference = typename basic_json::reference;

        /// default constructor
        iterator() = default;

        /// constructor for a given JSON instance
        explicit iterator(pointer object) noexcept
            : base_iterator(object)
        {}

        /// copy constructor
        iterator(const iterator& other) noexcept
            : base_iterator(other)
        {}

        /// copy assignment
        iterator& operator=(iterator other) noexcept(
            std::is_nothrow_move_constructible<pointer>::value and
            std::is_nothrow_move_assignable<pointer>::value and
            std::is_nothrow_move_constructible<internal_iterator>::value and
            std::is_nothrow_move_assignable<internal_iterator>::value
        )
        {
            base_iterator::operator=(other);
            return *this;
        }

        /// return a reference to the value pointed to by the iterator
        reference operator*()
        {
            return const_cast<reference>(base_iterator::operator*());
        }

        /// dereference the iterator
        pointer operator->()
        {
            return const_cast<pointer>(base_iterator::operator->());
        }

        /// post-increment (it++)
        iterator operator++(int)
        {
            iterator result = *this;
            base_iterator::operator++();
            return result;
        }

        /// pre-increment (++it)
        iterator& operator++()
        {
            base_iterator::operator++();
            return *this;
        }

        /// post-decrement (it--)
        iterator operator--(int)
        {
            iterator result = *this;
            base_iterator::operator--();
            return result;
        }

        /// pre-decrement (--it)
        iterator& operator--()
        {
            base_iterator::operator--();
            return *this;
        }

        /// add to iterator
        iterator& operator+=(difference_type i)
        {
            base_iterator::operator+=(i);
            return *this;
        }

        /// subtract from iterator
        iterator& operator-=(difference_type i)
        {
            base_iterator::operator-=(i);
            return *this;
        }

        /// add to iterator
        iterator operator+(difference_type i)
        {
            auto result = *this;
            result += i;
            return result;
        }

        /// subtract from iterator
        iterator operator-(difference_type i)
        {
            auto result = *this;
            result -= i;
            return result;
        }

        /// return difference
        difference_type operator-(const iterator& other) const
        {
            return base_iterator::operator-(other);
        }

        /// access to successor
        reference operator[](difference_type n) const
        {
            return const_cast<reference>(base_iterator::operator[](n));
        }

        /// return the value of an iterator
        reference value() const
        {
            return const_cast<reference>(base_iterator::value());
        }
    };