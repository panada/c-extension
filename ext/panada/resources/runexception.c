
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


/**
 * Hendle every runtime code execution errors.
 *
 * @author  Iskandar Soesman <k4ndar@yahoo.com>
 * @link    http://panadaframework.com/
 * @license http://www.opensource.org/licenses/bsd-license.php
 * @since   version experimental
 * @package Resources
 */
ZEPHIR_INIT_CLASS(Panada_Resources_RunException) {

	ZEPHIR_REGISTER_CLASS_EX(Panada\\Resources, RunException, panada, resources_runexception, zend_exception_get_default(TSRMLS_C), panada_resources_runexception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Panada_Resources_RunException, outputError) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	zend_print_zval(message, 0);

}

