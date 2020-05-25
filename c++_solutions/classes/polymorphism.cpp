class LRUCache:public Cache
{
        public:
        LRUCache(int);
        void set(int,int);
        int get(int);
        inline ~LRUCache(void){;}
};
LRUCache::LRUCache(int c)
{
    this->cp=c;
    head=tail=NULL;
}
void LRUCache::set(int k,int v)
{
    Node *N;
    if(mp.empty())
    {
        N=new Node(k,v);
        tail=head=N;
        mp[k]=N;
    }
        map<int,Node*>::iterator it=mp.find(k);
        if(it!=mp.end())
        {
            it->second->value=v;
            if(it->second==head)
            {
                return ;
            }
            it->second->prev->next=it->second->next;
            if(it->second==tail)
            {
                tail=tail->prev;
            }
            else
            {
                it->second->next->prev=it->second->prev;
            }
            it->second->next=head;
            it->second->prev=NULL;
            head->prev=it->second;
            head=it->second;
        }
        else
        {
            N=new Node(k,v);
            head->prev=N;
            N->next=head;
            head=N;
            mp[k]=N;
            if(mp.size()>cp)
            {
                tail=tail->prev;
                mp.erase(tail->next->key);
                delete(tail->next);
                tail->next=NULL;
            }
        }
}
int LRUCache::get(int k)
{
    map<int,Node*>::iterator it=mp.find(k);
    if(it!=mp.end())
    {
        return it->second->value;
    }
    else
    {
        return -1;
    }
}