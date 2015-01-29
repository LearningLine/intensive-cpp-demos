#include <iostream>
#include <string>

struct Excpt
{
    std::string message;
    Excpt(std::string msg) { message = msg; }
};

struct OutOfRange
{
    int index;
    int size;
    OutOfRange(int i, int s) { index = i; size = s; }
};

struct Overflow : Excpt
{
    std::string extra;
    Overflow(std::string msg, std::string ex) : Excpt(msg) {
        extra = ex;
    }
};

struct InvalidSize
{
};

void process(int x)
{
    std::cout << "entering process\n";
    if (x % 2 == 0) {
//        throw OutOfRange(5, 3);
//        throw InvalidSize();
//        throw Overflow();
        throw Overflow("sub class", "extra info");
    }
    std::cout << "leaving process\n";
}

void process()
{
    std::cout << "entering no arg process\n";

    try {
        std::cout << "calling process\n";
        process(4);
        std::cout << "returned from process\n";
    } catch (OutOfRange& expt) {
        std::cout << "excuting handler " << expt.index << ":" << expt.size << "\n";
    } catch (InvalidSize& expt) {
        std::cout << "excuting handler invalid size\n";
    } catch (Excpt& expt) {
        std::cout << "Just cleaning up\n";
        expt.message += " adding some info";
        throw;
    }
    
    std::cout << "leaving no arg process\n";
}

int main() {
    std::cout << "entering main\n";
    try {
        std::cout << "calling no arg process\n";
        process();
        std::cout << "returned from no arg process\n";
    } catch (Overflow& expt) {
        std::cout << "overflow handler " << expt.message << expt.extra << "\n";
    } catch (Excpt& expt) {
        std::cout << "excpt handler " << expt.message << "\n";
    } catch (OutOfRange& expt) {
        std::cout << "excuting handler " << expt.index << ":" << expt.size << "\n";
    } catch (InvalidSize& expt) {
        std::cout << "excuting handler invalid size\n";
    } catch (...) {
        std::cout << "excuting handler for unknown exception\n";
    }
    std::cout << "leaving main\n";
    return 0;
}
