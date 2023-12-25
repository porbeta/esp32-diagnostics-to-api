/**/
CREATE DATABASE IF NOT EXISTS espressif;

USE espressif;

CREATE TABLE IF NOT EXISTS `diagnostics` (
`id` int(20) NOT NULL AUTO_INCREMENT,
`datetime` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP, 
`chip_id` int(50) NOT NULL,
`voltage` decimal(9,3) NOT NULL,
PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ;

/**/
CREATE USER IF NOT EXISTS 'baseuser'@'localhost' identified BY 'password';

GRANT INSERT, SELECT, UPDATE, DELETE ON `espressif`.* TO 'baseuser'@'localhost' WITH GRANT OPTION;
