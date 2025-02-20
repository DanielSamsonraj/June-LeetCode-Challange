class Solution {
    private:
    class Trie
    {
    public:    
        Trie * children[26];
        bool isLeaf;
        int  wordIdx;
        int prefixCount;

        Trie()
        {
            isLeaf = false;
            wordIdx = 0;
            prefixCount = 0;
            fill_n(children, 26, nullptr);
        }

        ~Trie()
        {
            for(auto i=0; i<26; ++i) delete children[i];
        }
    };
        void insertWord(Trie *root,  const vector<string>& words, int idx)
        {
            int i, childID, len = words[idx].size();
            for(i=0, root->prefixCount++ ; i<len; ++i)
            {
                childID = words[idx][i]-'a';
                if(!root->children[childID]) root->children[childID] = new Trie();
                root = root->children[childID];
                ++root->prefixCount;
            }
            root->isLeaf = true; 
            root->wordIdx = idx;
        }

        Trie *buildTrie(const vector<string> &words)
        {
            Trie *root = new Trie();
            for(int i=0; i < words.size(); ++i) insertWord(root, words, i);
            return root;
        }

        int dfs_Trie(vector<string> &res, Trie *root, vector<vector<char>>& board, vector<string>& words, int row, int col)
        {
            int detected = 0;

            if(root->isLeaf)
            {
                ++detected;
                root->isLeaf = false;
                res.push_back(words[root->wordIdx]);
            }

            if( row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='*' || !root->children[ board[row][col]-'a'] || root->children[ board[row][col]-'a']->prefixCount <= 0 ) return detected;
            int curC = board[row][col] - 'a';
            board[row][col] = '*';
            detected += dfs_Trie(res, root->children[curC], board, words, row-1, col) + 
                   dfs_Trie(res, root->children[curC], board, words, row+1, col) +    
                   dfs_Trie(res, root->children[curC], board, words, row, col - 1) +    
                   dfs_Trie(res, root->children[curC], board, words, row, col + 1) ;
            root->prefixCount -=detected;
            board[row][col] = curC+'a';
            return detected;
        }

    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            int M, N, wordNum = words.size();
            vector<string> res;
            if( !(M = board.size()) || !(N = board[0].size()) || !wordNum) return res;
            Trie *root = buildTrie(words);
            for(auto i=0; i<M && root->prefixCount; ++i)
                for(auto j=0; j<N; ++j)
                    dfs_Trie(res, root, board, words, i, j);
            delete root;
            return res;
        }
    };
