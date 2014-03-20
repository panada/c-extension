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
    
    static private function _cache(string name)
    {
        var cfg = [];
        
        if ! isset self::config[name] {
            
            let cfg = require APP . "config/" .name.".php";
            let self::config[name] = cfg;
            
            return cfg;
        }
        else {
            return self::config[name];
        }
    }
    
    public static function main()
    {
        return self::__callStatic("main");
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