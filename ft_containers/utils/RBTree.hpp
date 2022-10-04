/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:48:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/04 15:30:40 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
#include "Node.hpp"
#define RED_COLOR   "\033[31m"
#define RESET       "\033[0m"

namespace ft
{
    template <typename T>
    class RBTree
    {
        private:
            Node<T> *root;

        protected:
            void rotateLeft(Node<T> *);
            void rotateRight(Node<T> *);
            void fixInsertRBTree(Node<T> *);
            void fixDeleteRBTree(Node<T> *);
        //void inorderBST(Node<T> *);
        //void preorderBST(Node<T> *);
            int getColor(Node<T> *);
            void setColor(Node<T> *, int);
            Node<T> *minValueNode(Node<T> *);
            Node<T> *maxValueNode(Node<T> *);
            Node<T> *insertBST(Node<T> *, Node<T> *);
            Node<T> *deleteBST(Node<T> *, T);
            Node<T> *getRoot(void) const;
            Node<T> *copyTree(Node<T> *root);
            Node<T> *clearRBTree(Node<T> *root);
            int     getMaxHeight(Node<T> *root);
            void    printTreeBST(Node<T> *node, int current_level, int max_level);
        //int getBlackHeight(Node<T> *);

        public:
            RBTree(void);
            RBTree(RBTree const &rbt);
            ~RBTree(void);
            RBTree &operator=(RBTree const &rbt);
                
            void    insertValue(T);
            void    deleteValue(T);
            void    printTree(void);
            //void    testRotateR(void);
            //void    testRotateL(void);
        //void merge(RBTree);
        //void inorder(void);
        //void preorder(void);
    };
}


#endif