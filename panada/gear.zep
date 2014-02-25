namespace Panada;

class Gear
{
    private arr = [];
    
    public function main()
    {
        
        let this->arr = ["nama": "kandar"];
        
        return this->arr;
    }
    
    public function setArr(key, val)
    {
        let this->arr[key] = val;
        
        return this;
    }
    
    static public function ask()
    {
        echo call_user_func_array("Panada\\Resources\\Config::database", []);
    }
}
