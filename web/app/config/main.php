<?php
return array(

    'defaultController' => 'Home',
    
    'indexFile' =>  'index.php/',

    'module' => array(
        'path' => 'app',
        'domainMapping' => array(),
    ),

    'vendor' => array(
        'path' => 'vendors/'
    ),

    'alias' => array(
        'controller' => array(
            'class' => 'Alias',
            'method' => 'index'
        ),
        'method' => 'alias'
    ),
);