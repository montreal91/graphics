
#include "color.h"

const AColor AColor::ABSOLUTE_BLACK( 0, 0, 0 );
const AColor AColor::ABSOLUTE_WHITE( 1, 1, 1 );
const AColor AColor::ABSOLUTE_RED( 1, 0, 0 );
const AColor AColor::ABSOLUTE_GREEN( 0, 1, 0 );
const AColor AColor::ABSOLUTE_BLUE( 0, 0, 1 );
const AColor AColor::RED( 0.25, 0.05, 0.15 );
const AColor AColor::GREEN( 0.05, 0.25, 0.15 );
const AColor AColor::BLUE( 0.05, 0.15, 0.25 );

AColor::AColor() {
    this->red   = 0;
    this->green = 0;
    this->blue  = 0;
}

AColor::AColor( const double red, const double green, const double blue ) {
    this->red   = red;
    this->green = green;
    this->blue  = blue;
}

AColor::AColor( const AColor& color ) {
    this->red   = color.GetRed();
    this->green = color.GetGreen();
    this->blue  = color.GetBlue();
}

AColor::~AColor() {
}

double
AColor::GetRed() const {
    return this->red;
}

double
AColor::GetGreen() const {
    return this->green;
}

double
AColor::GetBlue() const {
    return this->blue;
}

void
AColor::SetColor( const double red, const double green, const double blue ) {
    this->red   = red;
    this->green = green;
    this->blue  = blue;
}

void
AColor::SetRed( const double red ) {
    this->red = red;
}

void
AColor::SetGreen( const double green ) {
    this->green = green;
}

void
AColor::SetBlue( const double blue ) {
    this->blue = blue;
}
