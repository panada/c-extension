namespace Panada\Resources;

class Uri
{
    private pathUri;
    public baseUri;
    public defaultController = "Home";
    
    public function __construct()
    {
        var selfArray;
        var pathInfo = "";
        var selfKey;
        
        if isset _SERVER["ORIG_PATH_INFO"] {
            let pathInfo = _SERVER["ORIG_PATH_INFO"];
        }
        
        let selfArray       = explode("/", rtrim(_SERVER["PHP_SELF"].pathInfo, "/"));
        let selfKey         = array_search(INDEX_FILE, selfArray);
        let this->pathUri   = array_slice(selfArray, (selfKey + 1));
        let this->baseUri   = this->isHttps() ? "https://":"http://";
        let this->baseUri   .= _SERVER["HTTP_HOST"].implode("/", array_slice(selfArray, 0, selfKey)) ."/";
        
    }
    
    /**
     * Does this site use https?
     *
     * @return boolean
     */
    public function isHttps()
    {
	if isset _SERVER["HTTPS"] {
            
	    if strtolower(_SERVER["HTTPS"]) == "on" {
                return true;
            }
            
	    if _SERVER["HTTPS"] == "1" {
		return true;
            }
	}
        
	if isset _SERVER["SERVER_PORT"] && _SERVER["SERVER_PORT"] == "443" {
	    
	    return true;
	}

	return false;
    }
    
    /**
     * Clean the 'standard' model query.
     *
     * @param string
     * @return string
     */
    public function removeQuery(path)
    {
        var pathAr;
        
	let pathAr = explode("?", path);
	if count(pathAr) > 0 {
	    let path = pathAr[0];
        }
	
	return path;
    }
    
    /**
     * Break the string given from extractUriString() into class, method and request.
     *
     * @param    integer
     * @return  string
     */
    public function path(segment = false)
    {
        var path;
        
        if segment === false {
            return this->pathUri;
        }
        
        if fetch path, this->pathUri[segment] {
            if path != INDEX_FILE {
                return path;
            }
        }
        
        return false;
    }
    
    /**
     * Get class name from the url.
     *
     * @return  string
     */
    public function getClass()
    {
        var uriString;
        let uriString = this->path(0);
        
	if uriString {
	    
	    if this->stripUriString(uriString) {
		return uriString;
            }
	    else {
		return false;
            }
	}
	else {
	    return $this->defaultController;
	}
    }
    
    /**
     * Get method name from the url.
     *
     * @return  string
     */
    public function getMethod(defaultMethod = "index")
    {
        var uriString;
	let uriString = this->path(1);

	if uriString && ! empty uriString {

	    if this->stripUriString(uriString) {
		return uriString;
            }
	    else {
		return "";
            }
    
	}
	else {
	    return defaultMethod;
	}
    }
    
    /**
     * Get "GET" request from the url.
     *
     * @param    int
     * @return  array
     */
    public function getRequests(segment = 2)
    {
	if this->path(segment) {
	    return array_slice(this->path(), segment);
	}
	else {
	    return false;
	}
    }
    
    /**
     * Cleaner for class and method name
     *
     * @param string
     * @return boolean
     */
    public function stripUriString(uri)
    {
	return ! preg_match("/[^a-zA-Z0-9_.-]/", uri) ? true : false;
    }
    
    /**
     * Setter for default controller
     *
     * @param string $defaultController
     * @return void
     */
    public function setDefaultController(defaultController)
    {
	let this->defaultController = defaultController;
    }
    
    /**
     * Getter for default controller
     */
    public function getDefaultController()
    {
	return this->defaultController;
    }
    
    /**
     * Getter for baseUri
     *
     * @return string
     */
    public function getBaseUri()
    {
	return this->baseUri;
    }
}