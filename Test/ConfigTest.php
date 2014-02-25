<?php
namespace Test;

define('APP', dirname(__FILE__). '/app/' );

class ConfigTest extends \PHPUnit_Framework_TestCase
{
    public function testTrueIsTrue()
    {
        $foo = true;
        $this->assertTrue($foo);
    }
    
    public function testConfigMainIsArray()
    {
        $main = \Panada\Resources\Config::main();
        $this->assertTrue( is_array($main) );
    }
    
    public function testConfigDBIsArray()
    {
        $main = \Panada\Resources\Config::database();
        $this->assertTrue( is_array($main) );
    }
}