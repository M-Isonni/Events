#include <vector>
#include <memory>

template <class T>
class Event
{
    private:
    std::vector<T> functions;
    public:
    Event(){};
    ~Event(){};

    void AddListener(T listener)
    {
        functions.push_back(listener);
    }

    void RemoveListener(T listener)
    {   
        int len = functions.size();
        for(int i = 0; i< len;i++)
        {
            if(functions[i]==listener)
            {
                functions.erase(functions.begin()+i);
                break;
            }
        }
    }

    void ClearListeners()
    {
        functions.clear();
    }

    int GetListenersNum()
    {
        return functions.size();
    }

    void operator--()
    {
        functions.pop_back();
    }

    template<typename... Args>
    void Call(Args... args)
    {
        for(auto f : functions)
        {
            f(args...);
        }
    }  
};