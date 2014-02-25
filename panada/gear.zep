namespace Panada;

class Gear
{
    public function __construct()
    {
        
    }
    
    static public function ask()
    {
        echo call_user_func_array("Panada\\Resources\\Config::database", []);
    }
}
