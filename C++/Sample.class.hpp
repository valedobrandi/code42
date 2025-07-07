#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    
public:

    int foo;

    char a1;
    int a2;
    float a3;

    float const pi;
    int qd;

    Sample( char a1, int a2, float a3, float const f );
    ~Sample( void );

    void    publicBar( void ) const;

private:

    int     _privateFoo;
    void    _privateBar( void ) const;

};

#endif