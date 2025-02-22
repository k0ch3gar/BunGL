#ifndef IUPDATE_H
#define IUPDATE_H

class Updatable {
public:
    virtual ~Updatable() = default;

    virtual void Update(double delta) { }
};

#endif //IUPDATE_H
