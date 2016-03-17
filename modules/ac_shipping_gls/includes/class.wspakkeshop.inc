<?php
/**
 * @file
 * Access to external webservice.
 */

/**
 * Class to be used with GSL Pakkeshop webservice.
 *
 * This class will enable access to the GLS Pakkeshop webservice.
 * The service description is located at
 * http://www.gls.dk/webservices_v2/wsPakkeshop.asmx
 * Methods available in this class matches
 * technical documentation v.1.0.0.2 from GLS.
 *
 * Requirements:
 * PHP 5 with --enable-libxml --enable-soap.
 *
 * @author Dan Storm
 *
 * @created 15/01/2012
 *
 * @info http://catalystcode.net
 *
 * @version 1.0
 */
class CommerceShippingGlsWsPakkeshop {
  private $client;
  private $encoding;
  public $error;

  /**
   * This is the constructor method.
   *
   * This starts the SoapClient to GLS wsPakkeshop SOAP service.
   *
   * @params string
   *   The encoding you wish to use - default is ISO-8859-1.
   */
  public function __construct($encoding = 'ISO-8859-1') {
    $wsdl = "http://www.gls.dk/webservices_v2/wsPakkeshop.asmx?WSDL";
    $this->client = new SoapClient($wsdl, array('encoding' => $encoding));
  }

  /**
   * This method returns an array of objects with all parcel shops.
   *
   * @return mixed
   *   An array of objects or boolean false if service call failed.
   */
  public function getAllParcelShops() {
    try {
      $shops = $this->client->GetAllParcelShops(array());
      return $shops->GetAllParcelShopsResult->PakkeshopData;
    }
    catch (Exception $e) {
      $this->error = __METHOD__ . ': ' . $e->getMessage();
      return FALSE;
    }
  }

  /**
   * WARNING: This method is experimental according to the documentation.
   *
   * This method returns an array of objects with parcel shops
   * near the exact address specified. The street name and number
   * needs to be provided for this to work.
   * The service call will fail is address does not exist.
   *
   * @param string $street
   *   Exact street address with street number.
   * @param int $zip_code
   *   The zip code for the provided address.
   * @param int $amount
   *   The amount of parcel shops returned - default is 5.
   *
   * @return mixed
   *   An array of objects or boolean false if service call failed.
   */
  public function getNearestParcelShops($street, $zip_code, $amount = 5) {
    try {
      $location = array(
        'street' => $street,
        'zipcode' => $zip_code,
        'Amount' => $amount,
      );
      $shops = $this->client->GetNearstParcelShops($location);
      return $shops->GetNearstParcelShopsResult->parcelshops->PakkeshopData;
    }
    catch (Exception $e) {
      $this->error = __METHOD__ . ': ' . $e->getMessage();
      return FALSE;
    }
  }

  /**
   * Method to get shops related to shop number.
   *
   * This method returns an object for the specific parcel shop from it's
   * parcel shop number.
   *
   * @param int $parcel_shop_number
   *   The number of the parcel shop.
   *
   * @return mixed
   *   An object of the parcel shop or boolean false if service call failed.
   */
  public function getOneParcelShop($parcel_shop_number) {
    try {
      $parcel_shop = array(
        'ParcelShopNumber' => $parcel_shop_number,
      );
      $shop = $this->client->GetOneParcelShop($parcel_shop);
      return $shop->GetOneParcelShopResult;
    }
    catch (Exception $e) {
      $this->error = __METHOD__ . ': ' . $e->getMessage();
      return FALSE;
    }

  }

  /**
   * Method to get nearest shops related to zip code.
   *
   * This method returns an array of objects with parcel shops
   * near in the specified zip code.
   *
   * @param int $zip_code
   *   The zip code to find parcel shops in.
   *
   * @return mixed
   *   An array of objects or boolean false if service call failed.
   */
  public function getParcelShopsInZipCode($zip_code) {
    try {
      $zip_code_array = array(
        'zipcode' => $zip_code,
      );
      $shops = $this->client->GetParcelShopsInZipcode($zip_code_array);

      if (isset($shops->GetParcelShopsInZipcodeResult->PakkeshopData)) {
        if (!is_array($shops->GetParcelShopsInZipcodeResult->PakkeshopData)) {
          return array($shops->GetParcelShopsInZipcodeResult->PakkeshopData);
        }
        else {
          return $shops->GetParcelShopsInZipcodeResult->PakkeshopData;
        }
      }
      else {
        return array();
      }
    }
    catch (Exception $e) {
      $this->error = __METHOD__ . ': ' . $e->getMessage();
      return FALSE;
    }

  }

  /**
   * Method to get nearest shops to set location.
   *
   * This method returns an array of objects with parcel shops
   * near the exact address specified OR the zip code provided.
   * If the street name and number cannot be found in the provided zip code
   * the search for nearest parcel shops is expanded and limited to parcel
   * shops in the provided zip code.
   *
   * @param string $street
   *   Exact street address with street number.
   * @param int $zip_code
   *   The zip code for the provided address.
   * @param int $amount
   *   The amount of parcel shops returned - default is 5.
   *
   * @return mixed
   *   An array of objects or boolean false if service call failed.
   */
  public function searchNearestParcelShops($street, $zip_code, $amount = 5) {
    try {
      $location = array(
        'street' => $street,
        'zipcode' => $zip_code,
        'Amount' => $amount,
      );
      $shops = $this->client->SearchNearstParcelShops($location);

      $shops_result = $shops->SearchNearestParcelShopsResult;
      $shop_data = $shops_result->parcelshops->PakkeshopData;
      if (!is_array($shop_data)) {
        return array($shop_data);
      }

      return $shop_data;
    }
    catch (Exception $e) {
      $this->error = __METHOD__ . ': ' . $e->getMessage();
      return FALSE;
    }
  }

}
