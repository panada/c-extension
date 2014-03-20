namespace Panada;
use Panada\Resources;

class Gear
{
    private uriObj;
    private config;
    private firstUriPath = "Home";
    
    public function __construct()
    {
        error_reporting( E_ALL );
        spl_autoload_register([this, "loader"]);
        
        let this->config["main"] = Resources\Config::main();
        let this->uriObj = new Resources\Uri;
        //this->uriObj->setDefaultController("Home");
        let this->firstUriPath = ucwords( this->uriObj->getClass() );
        
        this->controllerHandler();
    }
    
    /**
     * Magic loader to load instantiated class.
     *
     * @param  string $file Class namespace.
     * @return void
     */
    public function loader(file)
    {
        var folder;
        var prefix;
        let prefix = explode("\\", file);

        switch prefix[0] {
            case "Models":
                let folder = APP;
                break;
            case "Libraries":
                let folder = APP;
                break;
            case "Controllers":
                let folder = APP;
                break;
            case "Resources":
                let folder = GEAR;
                break;
            case "Drivers":
                let folder = GEAR;
                break;
            case "Modules":
                let folder = this->config["main"]["module"]["path"];
                break;
            default:
                if ! isset this->config["main"]["namespace"] {
                    throw new Resources\RunException("Resource ".file." not available!");
                }
                
                if ! isset this->config["main"]["namespace"][prefix[0]] {
                    throw new Resources\RunException("Resource ".file." not available!");
                }
                
                let folder = this->config["main"]["namespace"][prefix[0]];
                
                break;
        }
        
        let file = folder . str_ireplace("\\", "/", file) . ".php";
        
        if ! file_exists(file) {
            throw new Resources\RunException("Resource ".file." not available!");
        }

        require file;
    }
    
    /**
     * Hendle the controller calling process.
     *
     * The steps is:
     *  - Does alias controller are defined in main config?
     *  - If not, is sub-controller exists?
     *  - If not, module with this name exists?
     *  - If all fault, then throw 404.
     *
     *  @return void
     */
    private function controllerHandler()
    {
        var instance;
        var request;
        var method;
        var classFile;
        var controllerNamespace;
        let controllerNamespace = "Controllers\\" . this->firstUriPath;
        let classFile = APP . "Controllers/" . this->firstUriPath . ".php";
        
        if ! file_exists(classFile) {
            this->subControllerHandler();
            return;
        }

        let method = this->uriObj->getMethod();
        let request = $this->uriObj->getRequests();
        
        if ! $request {
            let request = [];
        }

        if ! class_exists(controllerNamespace) {
            throw new Resources\RunException("Class ".controllerNamespace."  not found in ".classFile);
        }

        let instance = new {controllerNamespace}();

        if ! method_exists(instance, method) {

            let request = array_slice( this->uriObj->path(), 1);
            let method = this->config["main"]["alias"]["method"];

            if ! method_exists(instance, method) {
                throw new Resources\RunException("Method ".this->uriObj->getMethod()." does not exists in controller ".this->firstUriPath);
            }
        }

        this->run(instance, method, request);
    }
    
    private function subControllerHandler()
    {
    
    }
    
    /**
     * Call the controller's method
     *
     * @param  object $instance
     * @param  string $method
     * @param  array  $request
     * @return void
     */
    private function run(instance, method, request)
    {
        call_user_func_array([instance, method], request);
    }
}
