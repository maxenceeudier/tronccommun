/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_impl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:00:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/03 17:37:12 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"

namespace ft
{
    template <typename T>
    RBTree<T>::RBTree(void): root(NULL){}
    
    template <typename T>
    RBTree<T>::RBTree(RBTree<T> const &rbt){*this = rbt;}

    template <typename T>
    RBTree<T>::~RBTree(void){root = clearRBTree(root);}

    template <typename T>
    Node<T>    *RBTree<T>::clearRBTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        root->left = clearRBTree(root->left);
        root->right = clearRBTree(root->right);
        delete root;
        return (NULL);
    }

    template <typename T>
    RBTree<T> &RBTree<T>::operator=(RBTree<T> const &rbt)
    {
        root = copyTree(rbt->getRoot());
        return (*this);
    }

    template <typename T>
    Node<T> *RBTree<T>::copyTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        Node<T>    *node = new Node<T>(*root);
        node->left = copyTree(root->left);
        node->right = copyTree(root->rigth);
        return (node);
    }

    template <typename T>
    Node<T> *RBTree<T>::getRoot(void){return (root);}

    template <typename T>
    int RBTree<T>::getColor(Node<T> *node)
    {
        if (!node)
            return (BLACK);
        return (node->color);
    }

    template <typename T>
    void RBTree<T>::setColor(Node<T> *node, int color)
    {
        if (!node)
            return ;
        node->color = color;
    }
    
    template <typename T>
    Node<T> *RBTree<T>::minValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->left)
            return (node);
        return (minValueNode(node->left));
    }

    template <typename T>
    Node<T> *RBTree<T>::maxValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->right)
            return (node);
        return (maxValueNode(node->right));
    }

    template <typename T>
    Node<T> *RBTree<T>::insertBST(Node<T> *root, Node<T> *node)
    {
        if (!root)
            return (node);
        if (root->data < node->data)
        {
            root->right = insertBST(root->right, node);
            root->right->parent = root;
        }
        if (root->data > node->data)
        {
            root->left = insertBST(root->left, node);
            root->left->parent = root;
        }
        return (root);
    }

    template <typename T>
    void RBTree<T>::insertValue(T data)
    {
        Node<T> *node = new Node<T>(data);
        root = insertBST(root, node);
        //fixInsertRBTree(node);
    }
    
    template <typename T>
    Node<T> *RBTree<T>::deleteBST(Node<T> *root, T data)
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
    
    template <typename T>
    void RBTree<T>::deleteValue(T data)
    {
        //Node<T> *node = 
        deleteBST(root, data);
        //fixDeleteRBTree(node);
    }
    
    template <typename T>
    void  RBTree<T>::printTreeBST(Node<T> *node, int current_level, int max_level)
    {
        int i;
        
        if (node) 
        {
            printTreeBST(node->right, current_level + 1, max_level);
            for (i = 0; i < current_level; i++)
                std::cout << "    ";
            std::cout << node->data << std::endl;
            printTreeBST(node->left, current_level + 1, max_level);
        } 
        else 
        {
            if (current_level < max_level)
            {
                printTreeBST(NULL, current_level + 1, max_level);
                for (i = 0; i < current_level; i++)
                    std::cout << "    ";
                std::cout << "..\n";
                printTreeBST(NULL, current_level + 1, max_level);
            }
        }
    }
    
    template <typename T>
    void    RBTree<T>::printTree(void)
    {
        std::cout << "print Tree:\n";
        printTreeBST(root, 0, getMaxHeight(root));
    }

    template <typename T>
    int     RBTree<T>::getMaxHeight(Node<T> *root)
    {
        int height1 = 1;
        int height2 = 1;

        if (!root)
            return (0);
        height1 += getMaxHeight(root->right);
        height2 += getMaxHeight(root->left);
        return (std::max(height1, height2));
    }

    /*template <typename T>
    void RBTree<T>::inorderBST(Node<T> *ptr)
    {
        if (!ptr)
            return ;
        inorderBST(ptr->left);
        std::cout << ptr->data << " " << ptr->color << std::endl;
        inorderBST(ptr->right);
    }

    template <typename T>
    void RBTree<T>::inorder()
    {
        inorderBST(root);
        std::cout << "-------" << std::endl;
    }
    
    template <typename T>
    void RBTree<T>::preorderBST(Node<T> *ptr)
    {
        if (ptr == nullptr)
            return; 
        std::cout << ptr->data << std::endl;
        preorderBST(ptr->left);
        preorderBST(ptr->right);
    }

    template <typename T>
    void RBTree<T>::preorder()
    {
        preorderBST(root);
        std::cout << "-------" << std::endl;
    }*/
}
