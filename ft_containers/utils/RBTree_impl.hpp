/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_impl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:00:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/13 22:30:57 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_IMPL_HPP
#define RBTREE_IMPL_HPP
#include "RBTree.hpp"

namespace ft
{
    template <typename T, class Allocator>
    RBTree<T, Allocator>::RBTree(const Allocator &alloc): root(NULL), _alloc(alloc){}
    
    template <typename T, class Allocator>
    RBTree<T, Allocator>::RBTree(RBTree const &rbt): _alloc(rbt._alloc){*this = rbt;}

    template <typename T, class Allocator>
    RBTree<T, Allocator>::~RBTree(void){root = clearRBTree(root);}

    template <typename T, class Allocator>
    Node<T>    *RBTree<T, Allocator>::clearRBTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        root->left = clearRBTree(root->left);
        root->right = clearRBTree(root->right);
        _alloc.destroy(root);
        _alloc.deallocate(root, 1);
        return (NULL);
    }

    template <typename T, class Allocator>
    RBTree<T, Allocator> &RBTree<T, Allocator>::operator=(RBTree<T, Allocator> const &rbt)
    {
        _alloc = rbt._alloc;
        root = copyTree(rbt.getRoot());
        return (*this);
    }

    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::copyTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        Node<T>    *node = _alloc.allocate(1);
        _alloc.construct(node, *root);
        node->left = copyTree(root->left);
        node->right = copyTree(root->right);
        return (node);
    }

    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::getRoot(void) const {return (root);}

    template <typename T, class Allocator>
    int RBTree<T, Allocator>::getColor(Node<T> *node)
    {
        if (!node)
            return (BLACK);
        return (node->color);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::setColor(Node<T> *node, int color)
    {
        if (!node)
            return ;
        node->color = color;
    }
    
    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::minValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->left)
            return (node);
        return (minValueNode(node->left));
    }

    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::maxValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->right)
            return (node);
        return (maxValueNode(node->right));
    }

    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::insertBST(Node<T> *root, Node<T> *node, int *i)
    {
        if (!root)
            return (node);
        if (root->data < node->data)
        {
            root->right = insertBST(root->right, node, i);
            root->right->parent = root;
        }
        if (root->data > node->data)
        {
            root->left = insertBST(root->left, node, i);
            root->left->parent = root;
        }
        if (root->data.first == node->data.first)
            *i = 0;
        return (root);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::fixInsertRBTree(Node<T> *ptr)
    {
        Node<T> *parent = NULL;
        Node<T> *grandparent = NULL;
        while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) 
        {
            parent = ptr->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left) 
            {
                Node<T> *uncle = grandparent->right;
                if (getColor(uncle) == RED) 
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    ptr = grandparent;
                }
                else
                {
                    if (ptr == parent->right)
                    {
                        rotateLeft(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateRight(grandparent);
                    ft::swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            } 
            else 
            {
                Node<T> *uncle = grandparent->left;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    ptr = grandparent;
                } 
                else 
                {
                    if (ptr == parent->left) 
                    {
                        rotateRight(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateLeft(grandparent);
                    ft::swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            }
        }
        setColor(root, BLACK);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::insertValue(T data)
    {
        int i = 1;
        Node<T>    *node = _alloc.allocate(1);
        _alloc.construct(node, data);
        root = insertBST(root, node, &i);
        if (!i)
        {
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }
        else
            fixInsertRBTree(node);
    }
    
   
    template <typename T, class Allocator>
    void  RBTree<T, Allocator>::printTreeBST(Node<T> *node, int current_level, int max_level)
    {
        int i;
        
        if (node) 
        {
            printTreeBST(node->right, current_level + 1, max_level);
            for (i = 0; i < current_level; i++)
                std::cout << "                          ";
            if (node->color == RED)
                std::cout << RED_COLOR;
            std::cout << node->data << RESET << std::endl;
            printTreeBST(node->left, current_level + 1, max_level);
        } 
        else 
        {
            if (current_level < max_level)
            {
                printTreeBST(NULL, current_level + 1, max_level);
                for (i = 0; i < current_level; i++)
                    std::cout << "                          ";
                std::cout << "..\n";
                printTreeBST(NULL, current_level + 1, max_level);
            }
        }
    }
    
    template <typename T, class Allocator>
    void    RBTree<T, Allocator>::printTree(void)
    {
        std::cout << "print Tree:\n";
        printTreeBST(root, 0, getMaxHeight(root));
    }

    template <typename T, class Allocator>
    int     RBTree<T, Allocator>::getMaxHeight(Node<T> *root)
    {
        int height1 = 1;
        int height2 = 1;

        if (!root)
            return (0);
        height1 += getMaxHeight(root->right);
        height2 += getMaxHeight(root->left);
        return (std::max(height1, height2));
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::rotateLeft(Node<T> *node)
    {
        if (!node->right)
            return ;
        Node<T> *right_child = node->right;
        node->right = right_child->left;

        if (node->right != NULL)
            node->right->parent = node;
        right_child->parent = node->parent;
        if (!node->parent)
            root = right_child;
        else if (node == node->parent->right)
            node->parent->right = right_child;
        else
            node->parent->left = right_child;
        right_child->left = node;
        node->parent = right_child;
    }
    
    template <typename T, class Allocator>
    void RBTree<T, Allocator>::rotateRight(Node<T> *node)
    {
       if (!node->left)
            return ;
        Node<T> *left_child = node->left;
        node->left = left_child->right;

        if (node->left != NULL)
            node->left->parent = node;
        left_child->parent = node->parent;
        if (!node->parent)
            root = left_child;
        else if (node == node->parent->right)
            node->parent->right = left_child;
        else
            node->parent->left = left_child;
        left_child->right = node;
        node->parent = left_child;
    }


    template <typename T, class Allocator>
    Node<T> *RBTree<T, Allocator>::deleteBST(Node<T> *root, T data)
    {
        T   temp;

        if (!root)
            return (root);
        if (root->data < data)
            return (deleteBST(root->right, data));
        if (root->data > data)
            return (deleteBST(root->left, data));
        if (!root->right)
            return (root);
        temp = minValueNode(root->right)->data;
        root->data = temp;
        return (deleteBST(root->right, temp));
    }
    
    template <typename T, class Allocator>
    void RBTree<T, Allocator>::deleteValue(T data)
    {
        Node<T> *node = deleteBST(root, data);
        fixDeleteRBTree(node);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::fixDeleteRBTree(Node<T> *node)
    {
        if (node == nullptr)
            return;

        if (node == root)
        {
            root = nullptr;
            return;
        }

        if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
        {
            Node<T> *child = node->left != nullptr ? node->left : node->right;

            if (node == node->parent->left)
            {
                node->parent->left = child;
                if (child != nullptr)
                    child->parent = node->parent;
                setColor(child, BLACK);
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                //delete (node);
            }
            else
            {
                node->parent->right = child;
                if (child != nullptr)
                    child->parent = node->parent;
                setColor(child, BLACK);
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                //delete (node);
            }
        }
        else
        {
            Node<T> *brother = nullptr;
            Node<T> *parent = nullptr;
            Node<T> *ptr = node;
            setColor(ptr, DOUBLE_BLACK);
            while (ptr != root && getColor(ptr) == DOUBLE_BLACK)
            {
                parent = ptr->parent;
                if (ptr == parent->left)
                {
                    brother = parent->right;
                    if (getColor(brother) == RED)
                    {
                        setColor(brother , BLACK);
                        setColor(parent, RED);
                        rotateLeft(parent);
                    }
                    else
                    {
                        if (getColor(brother->left) == BLACK && getColor(brother->right) == BLACK)
                        {
                            setColor(brother, RED);
                            if(getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            ptr = parent;
                        }
                        else
                        {
                            if (getColor(brother->right) == BLACK)
                            {
                                setColor(brother->left, BLACK);
                                setColor(brother, RED);
                                rotateRight(brother);
                                brother = parent->right;
                            }
                            setColor(brother, parent->color);
                            setColor(parent, BLACK);
                            setColor(brother->right, BLACK);
                            rotateLeft(parent);
                            break;
                        }
                    }
                }
                else
                {
                    brother = parent->left;
                    if (getColor(brother) == RED)
                    {
                        setColor(brother, BLACK);
                        setColor(parent, RED);
                        rotateRight(parent);
                    }
                    else
                    {
                        if (getColor(brother->left) == BLACK && getColor(brother->right) == BLACK)
                        {
                            setColor(brother, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            ptr = parent;
                        }
                        else
                        {
                            if (getColor(brother->left) == BLACK)
                            {
                                setColor(brother->right, BLACK);
                                setColor(brother, RED);
                                rotateLeft(brother );
                                brother = parent->left;
                            }
                            setColor(brother, parent->color);
                            setColor(parent, BLACK);
                            setColor(brother->left, BLACK);
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (node == node->parent->left)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            //delete(node);
            setColor(root, BLACK);
        }
    }
    
    /*
    template <typename T, class Allocator>
    void    RBTree<T, Allocator>::testRotateR(void){rotateRight(root);}
    
    template <typename T, class Allocator>
    void    RBTree<T, Allocator>::testRotateL(void){rotateLeft(root);}
    
    template <typename T, class Allocator>
    void RBTree<T, Allocator>::inorderBST(Node<T> *ptr)
    {
        if (!ptr)
            return ;
        inorderBST(ptr->left);
        std::cout << ptr->data << " " << ptr->color << std::endl;
        inorderBST(ptr->right);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::inorder()
    {
        inorderBST(root);
        std::cout << "-------" << std::endl;
    }
    
    template <typename T, class Allocator>
    void RBTree<T, Allocator>::preorderBST(Node<T> *ptr)
    {
        if (ptr == nullptr)
            return; 
        std::cout << ptr->data << std::endl;
        preorderBST(ptr->left);
        preorderBST(ptr->right);
    }

    template <typename T, class Allocator>
    void RBTree<T, Allocator>::preorder()
    {
        preorderBST(root);
        std::cout << "-------" << std::endl;
    }*/
}

#endif
