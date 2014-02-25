/**
 * Handler for configuration.
 *
 * @author  Iskandar Soesman <k4ndar@yahoo.com>
 * @link    http://panadaframework.com/
 * @license http://www.opensource.org/licenses/bsd-license.php
 * @since   version experimental
 * @package Resources
 */
namespace Panada\Resources;
use Exception;

class Config
{
    static private config;
    
    static public function _cache(string name)
    {
        var cfg = [];
        
        if ! isset self::config[name] {
            
            require APP . "config/" .name.".php";
            
            let cfg = call_user_func(name);
            let self::config[name] = cfg;
            
            return cfg;
        }
        else {
            return self::config[name];
        }
    }
    
    static public function debug(name = "main")
    {
        require APP . "config/" .name.".php";;
        
        return call_user_func(name);
    }
    
    static public function main()
    {
        return self::_cache("main");
    }
    
    static public function session()
    {
        return self::_cache("session");
    }
    
    static public function cache()
    {
        return self::_cache("cache");
    }
    
    static public function database()
    {
        return self::_cache("database");
    }
    
    public static function __callStatic(string name, array arguments = [] )
    {
        // Does cache for this config exists?
        if isset self::config[name] {
            return self::config[name];
        }
        
        var file, e;
        let file = APP . "config/".name.".php";
        
        // Does the config file exists?
        try{
            if ! file_exists(file) {
                throw new RunException("Config file in ".file." does not exits");
            }
            
            return self::_cache(name);
        }
        catch RunException, e {
            RunException::outputError(e->getMessage());
        }
    }
}