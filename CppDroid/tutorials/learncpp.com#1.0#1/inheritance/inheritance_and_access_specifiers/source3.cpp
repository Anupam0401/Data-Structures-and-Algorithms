// Inherit from Base publicly
class Pub: public Base
{
};

// Inherit from Base privately
class Pri: private Base
{
};

// Inherit from Base protectedly
class Pro: protected Base
{
};

class Def: Base // Defaults to private inheritance
{
};