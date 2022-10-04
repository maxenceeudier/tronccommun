#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        typedef T value_type;
        typedef Allocator                                       allocator_type;
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef value_type&                                     reference
        typedef const value_type&                               const_reference;
        typedef Allocator::pointer                              pointer;
        typedef Allocator::const_pointer                        const_pointer;
        typedef std::random_access_iterator<value_type>         iterator;
        typedef std::random_access_iterator<const value_type>   const_iterator;
        typedef std::reverse_iterator<iterator>                 reverse_iterator;
        typedef std::reverse_iterator<const_iterator>           const_reverse_iterator;

        public:
            /*---------fonction de base----------*/
            vector(void);
            vector(const vector &cpy);
            ~vector(void);
            vector  &operator=(const vector &cpy);
            //assign
            void assign(size_type count, const T &value);
            template<class InputIt>
            void assign(InputIt first, InputIt last);
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
            template< class InputIt >
            iterator insert( const_iterator pos, InputIt first, InputIt last );
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
    bool operator==( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

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