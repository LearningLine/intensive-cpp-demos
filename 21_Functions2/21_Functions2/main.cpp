#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

std::vector<int> getRandomInts(int start, int end, int num)
{
    std::vector<int> ret;
    std::uniform_int_distribution<> dis(start, end);

    for (int i = 0; i < num; ++i) {
        ret.push_back(dis(gen));
    }
    return ret;
}

template<typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end) {
        std::cout << *begin << " "; ++begin;
    }
    std::cout << "\n";
}

struct IsMultOf
{
    int mult;
    IsMultOf(int m) : mult(m) {}

    bool operator()(int val)
    {
        return val % mult == 0;
    }
};

void process(std::vector<int> v, int mult)
{
    auto c = std::count_if(v.begin(), v.end(),
                           [mult](int val) -> bool {
                               return val % mult == 0;
                           }
                           );
//    auto c = std::count_if(v.begin(), v.end(),
//                           IsMultOf(mult)
//                           );
    
    std::cout << "Number of mults of " << mult << "'s is " << c << "\n";
}

int main()
{
    auto v = getRandomInts(1, 100, 15);
    
    print(v.begin(), v.end());
    std::sort(v.begin(), v.end(), [](int l, int r) { return l > r; });
    print(v.begin(), v.end());
    
    process(v, 6);
    
    int a = 3;
    auto lam = [a](int& x) { x += a; };
    
    int z = 13;
    lam(z);
    lam(z);
    std::cout << "z is now " << z << "\n";
}

//struct Person
//{
//    std::string name_;
//    int age_;
//};
//
//bool operator==(Person const& l, Person const& r)
//{
//    return l.name_ == r.name_ && l.age_ == r.age_;
//}
//
//namespace std {
//    template<>
//    struct hash<Person>
//    {
//        std::size_t operator()(Person const& p) const
//        {
//            return std::hash<std::string>()(p.name_);
//        }
//    };
//}
//
//
//int main()
//{
//    std::unordered_set<Person> people;
//    
//    people.insert(Person{"Bradley", 25});
//    
//    return 0;
//}

////typedef void (*FUNC)(int&);
//
//template<typename Iter, typename FUNC>
//void myForEach(Iter begin, Iter end, FUNC func)
//{
//    while (begin != end) {
//        func(*begin); ++begin;
//    }
//}
//
//bool gt(int l, int r)
//{
//    return l > r;
//}
//
//bool isEven(int val)
//{
//    return val % 2 == 0;
//}
//
//struct IsMultOf
//{
//    int mult;
//    IsMultOf(int m) : mult(m) {}
//    
//    bool operator()(int val)
//    {
//        return val % mult == 0;
//    }
//};
//
//bool isMultOf3(int val)
//{
//    return val % 3 == 0;
//}
//
//struct AddNum
//{
//    int numToAdd;
//    AddNum(int num) : numToAdd(num) {}
//    void operator()(int& val) {
//        val += numToAdd;
//    }
//};
//
//void addTwo(int& val) {
//    val += 2;
//}
//
//int main() {
//    std::vector<int> v = getRandomInts(1, 100, 20);
//    
//    print(v.begin(), v.end());
//    
//    std::sort(v.begin(), v.end(), gt);
//    
//    print(v.begin(), v.end());
//    
//    auto c = std::count_if(v.begin(), v.end(), IsMultOf(6));
//    
//    std::cout << "Number of multiples is " << c << "\n";
//    
//    myForEach(v.begin(), v.end(), addTwo);
//    print(v.begin(), v.end());
//
//    
//    AddNum addThree(3);
//    
//    int x = 5;
//    
//    addThree(x);
//    
//    std::cout << "x is now " << x << "\n";
//    
//    myForEach(v.begin(), v.end(), AddNum(17));
//    print(v.begin(), v.end());
//
//    return 0;
//}

//struct Person
//{
//    std::string name_;
//    int age_;
//};
//
//bool operator<(Person const& lhs, Person const& rhs)
//{
//    return lhs.name_ < rhs.name_;
//}
//
//int main() {
//    std::set<Person> personSet;
//    
//    Person p1 { "Bradley", 25 };
//    Person p2 { "Paul", 34 };
//    Person p3 { "Mike", 2 };
//    Person p4 { "John", 25 };
//    Person p5 { "Bradley", 15 };
//    Person p6 { "Mike", 2 };
//    
//    personSet.insert(p1);
//    personSet.insert(p2);
//    personSet.insert(p3);
//    personSet.insert(p4);
//    personSet.insert(p5);
//    personSet.insert(p6);
//    
//    for (auto const & p : personSet) {
//        std::cout << "name: " << p.name_ << " age: " << p.age_ << "\n";
//    }
//    
//    return 0;
//}
//void upperCase(char& ch)
//{
//    if (isalpha(ch)) {
//        ch = toupper(ch);
//    }
//}
//
//
//int main() {
//    std::unordered_map<std::string, int> wordsCount;
//    
//    std::ifstream is("/Users/ben/tmp/Tale.txt");
//    if (!is) { std::cerr << "Cannot open Tale.txt!\n"; return 1;}
//    
//    std::string s;
//    while (is >> s) {
//        
//        std::for_each(s.begin(), s.end(), upperCase);
//        
//        wordsCount[s]++;
//    }
//    
//    for (auto const& kv : wordsCount) {
//        std::cout << kv.second << ": " << kv.first << " ";
//    }
//    std::cout << "\n";
//    
//    return 0;
//}


//int x = 10;
//
//int* px = &x;
//

//
//
//void (*pFunc)(char& c);
//
//typedef void (*PFUNC1)(char& c);
//using PFUNC2 = void(char&c);
//PFUNC1 pfun;
//pfun = &upperCase;
//
//int* pi = &x;






//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<> dis(1, 100);
//
//ifstream is("File.txt");
//if (!is) {
//cerr << "Cannot open File.txt!" << endl;
//return 1; }


//struct Person
//{
//    std::string name_;
//    int age_;
//    virtual void birthday() final { ++age_; }
//    virtual ~Person() = default;
//};
//
//struct Student : public Person
//{
//    int id_;
//};

