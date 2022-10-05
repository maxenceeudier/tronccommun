#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        typedef T                                               value_type;
        typedef Allocator                                       allocator_type;
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef value_type&                                     reference
        typedef const value_type&                               const_reference;
        typedef Allocator::pointer                              pointer;
        typedef Allocator::const_pointer                        const_pointer;
        typedef std::iterator_traits<value_type>                iterator;
        typedef std::iterator_traits<const value_type>          const_iterator;
        typedef std::reverse_iterator<iterator>                 reverse_iterator;
        typedef std::reverse_iterator<const_iterator>           const_reverse_iterator;

        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _end_capacity;
        public:
            /*---------basic function----------*/
            //constructor
            explicit vector(const Allocator& alloc);
            explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator());
            //this constructor is declare here because of "enable_if" to make shure inputIt is an itterator
            template <class InputIt, typename ft::enable_if<InputIt::input_iter, InputIt>::type = NULL >
            vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
            : _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
            {
                difference_type n = ft::distance(first, last);
                _start = _alloc.allocate(n);
                _end_capacity = _start + n;
                _end = _start;
                while (n--)
                {
                    _alloc.constuct(_end, *first++);
                    _end++;
                }
            };
            vector(const vector &cpy);
            //destructor
            ~vector(void);
            //assignement operator
            vector  &operator=(const vector &cpy);
            //assign
            void assign(size_type count, const T &value);
            //this assign is declare here because of "enable_if" to make shure inputIt is an itterator
            template<class InputIt, typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr>
            void assign(InputIt first, InputIt last)
            {
                this->clear();
                this->insert(_start, first, last);
            };
            //get_alocator
            allocator_type get_allocator() const;

            /*------------acces elements-----------*/
            //at
            reference at(size_type pos);
            const_reference at(size_type pos) const;
            //[]
            reference operator[]( size_type pos );
            const_reference operator[]( size_type pos ) const;
            //front
            reference front();
            const_reference front() const;
            //back
            reference back();
            const_reference back() const;
            //data
            T* data();
            const T* data() const;

            /*-------------iterators----------------*/
            //begin
            iterator begin();
            const_iterator begin() const;
            //end
            iterator end();
            const_iterator end() const;
            //rbegin
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            //rend
            reverse_iterator rend();
            const_reverse_iterator rend() const;

            /*---------------capacity---------------*/
            //empty
            bool empty() const;
            //size
            size_type size() const;
            //max_size
            size_type max_size() const;
            //reserve
            void reserve(size_type new_cap);
            //capacity
            size_type capacity() const;
            
            /*-----------------modifiers-------------*/
            //clear
            void clear();
            //insert
            iterator insert( const_iterator pos, const T& value );
            iterator insert( const_iterator pos, size_type count, const T& value );
            //this insert is declare here because of "enable_if" to make shure inputIt is an itterator
            template< class InputIt >
            iterator insert( const_iterator pos, InputIt first, InputIt last , ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr);
            //erase
            iterator erase( iterator pos );
            iterator erase( iterator first, iterator last );
            //push_back
            void push_back( const T& value );
            //pop_back
            void pop_back();
            //resize
            void resize( size_type count, T value = T() );
            //swap
            void swap( vector& other );
    };

    template< class T, class Alloc >
    bool operator==(const std::vector<T,Alloc>& lhs, \
    const std::vector<T,Alloc>& rhs)
    {
        vector<T, Alloc>::iterator itL = lhs.begin();
        vector<T, Alloc>::iterator itR = rhs.begin(); 
        while (itL != lhs.end())
        {
            if (itR == rhs.end() || *itl != *itR)
                return (false);
            itL++;
            itR++;
        }
        return (true);
    };

    template< class T, class Alloc >
    bool operator!=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );
    
    template< class T, class Alloc >
    bool operator<( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator<=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );
    
    template< class T, class Alloc >
    void swap( std::vector<T,Alloc>& lhs,
           std::vector<T,Alloc>& rhs );
}

#endif