#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TreeNode
{
    string identifier;
   int count;
   TreeNode* left;
   TreeNode* right;
};

void insert(TreeNode*& root, string identifier)
{
   if (root == nullptr)
   {
      root = new TreeNode;
      root->identifier = identifier;
      root->count = 1;
      root->left = nullptr;
      root->right = nullptr;
   }
   else if (identifier < root->identifier)
   {
      insert(root->left, identifier);
   }
   else if (identifier > root->identifier)
   {
      insert(root->right, identifier);
   }
   else
   {
      root->count++;
   }
}

void print(TreeNode* root)
{
   if (root != nullptr)
   {
      print(root->left);
      cout << root->identifier << " : " << root->count << endl;
      print(root->right);
   }
}

void buildIdentifierTree(const string& filename, TreeNode*& root)
{
   ifstream file(filename);
   if (!file)
   {
      cout << "Неможливо відкрити файл: " << filename << endl;
      return;
   }

   string word;
   while (file >> word)
   {
      string identifier = "";
      for (char c : word)
      {
         if (isalnum(c) || c == '_')
         {
            identifier += c;
         }
         else
         {
            if (!identifier.empty())
            {
               insert(root, identifier);
               identifier = "";
            }
         }
      }
      if (!identifier.empty())
      {
         insert(root, identifier);
      }
   }

   file.close();
}

int main() {
   TreeNode* root = nullptr;
   string filename = "/Users/user/text12_10.txt";

   buildIdentifierTree(filename, root);

   print(root);

   return 0;
}



