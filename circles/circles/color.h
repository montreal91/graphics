
#ifndef __COLOR_H__
#define __COLOR_H__

class AColor {
public:
    AColor();
    AColor( const double red, const double green, const double blue );
    AColor( const AColor& color );
    ~AColor();

    static const    AColor ABSOLUTE_BLACK;
    static const    AColor ABSOLUTE_WHITE;
    static const    AColor ABSOLUTE_RED;
    static const    AColor ABSOLUTE_GREEN;
    static const    AColor ABSOLUTE_BLUE;
    static const    AColor RED;
    static const    AColor GREEN;
    static const    AColor BLUE;

    double          GetRed() const;
    double          GetGreen() const;
    double          GetBlue() const;
    void            SetColor( const double red, const double green, const double blue );
    void            SetRed( const double red );
    void            SetGreen( const double green );
    void            SetBlue( const double blue );

private:
    double red, green, blue;
    
};

#endif
