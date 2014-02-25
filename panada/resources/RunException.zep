/**
 * Hendle every runtime code execution errors.
 *
 * @author  Iskandar Soesman <k4ndar@yahoo.com>
 * @link    http://panadaframework.com/
 * @license http://www.opensource.org/licenses/bsd-license.php
 * @since   version experimental
 * @package Resources
 */
namespace Panada\Resources;
use Exception;

class RunException extends Exception
{
    public static function outputError(message)
    {
        echo message;
    }
}