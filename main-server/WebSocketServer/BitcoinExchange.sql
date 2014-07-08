SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP SCHEMA IF EXISTS `BitcoinExchange` ;
CREATE SCHEMA IF NOT EXISTS `BitcoinExchange` DEFAULT CHARACTER SET cp850 COLLATE cp850_bin ;
SHOW WARNINGS;
USE `BitcoinExchange` ;

-- -----------------------------------------------------
-- Table `BitcoinExchange`.`Account`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `BitcoinExchange`.`Account` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `BitcoinExchange`.`Account` (
  `ac_number` VARCHAR(45) NOT NULL,
  `ac_type` TINYINT(1) NULL,
  `email` VARCHAR(255) NULL,
  `pwd_enc` VARCHAR(45) NULL,
  `civility` VARCHAR(5) NULL,
  `first_name` VARCHAR(45) NULL,
  `second_name` VARCHAR(45) NULL,
  `is_political` TINYINT(1) NULL,
  `citizenship` VARCHAR(45) NULL,
  `country_residence` VARCHAR(45) NULL,
  `date_of_birth` DATE NULL,
  `phone_number` VARCHAR(45) NULL,
  PRIMARY KEY (`ac_number`))
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `BitcoinExchange`.`BankDetails`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `BitcoinExchange`.`BankDetails` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `BitcoinExchange`.`BankDetails` (
  `Account_ac_number` VARCHAR(45) NOT NULL,
  `account_name` VARCHAR(255) NULL,
  `int_bank_ac_number` VARCHAR(255) NOT NULL,
  `bic` VARCHAR(255) NOT NULL,
  `agency` VARCHAR(255) NULL,
  `agency_city` VARCHAR(70) NULL,
  PRIMARY KEY (`Account_ac_number`, `int_bank_ac_number`, `bic`),
  CONSTRAINT `fk_BankDetails_Account1`
    FOREIGN KEY (`Account_ac_number`)
    REFERENCES `BitcoinExchange`.`Account` (`ac_number`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

SHOW WARNINGS;
CREATE INDEX `fk_BankDetails_Account1_idx` ON `BitcoinExchange`.`BankDetails` (`Account_ac_number` ASC);

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `BitcoinExchange`.`Bitcoin_Transactions`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `BitcoinExchange`.`Bitcoin_Transactions` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `BitcoinExchange`.`Bitcoin_Transactions` (
  `Account_ac_number` VARCHAR(45) NOT NULL,
  `Received` DECIMAL(10) NULL,
  `Withdraw` DECIMAL(10) NOT NULL,
  `Comments` VARCHAR(255) NOT NULL,
  `Balance` DECIMAL(10) NULL,
  PRIMARY KEY (`Account_ac_number`, `Withdraw`, `Comments`),
  CONSTRAINT `fk_BankDetails_Account10`
    FOREIGN KEY (`Account_ac_number`)
    REFERENCES `BitcoinExchange`.`Account` (`ac_number`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

SHOW WARNINGS;
CREATE INDEX `fk_BankDetails_Account1_idx` ON `BitcoinExchange`.`Bitcoin_Transactions` (`Account_ac_number` ASC);

SHOW WARNINGS;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
