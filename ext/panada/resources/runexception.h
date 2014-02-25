
extern zend_class_entry *panada_resources_runexception_ce;

ZEPHIR_INIT_CLASS(Panada_Resources_RunException);

PHP_METHOD(Panada_Resources_RunException, outputError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_runexception_outputerror, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(panada_resources_runexception_method_entry) {
	PHP_ME(Panada_Resources_RunException, outputError, arginfo_panada_resources_runexception_outputerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
