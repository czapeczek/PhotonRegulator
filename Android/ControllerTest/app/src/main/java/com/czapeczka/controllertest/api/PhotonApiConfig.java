package com.czapeczka.controllertest.api;

/**
 * Created by Damian Walczak on 14/12/15.
 */
public final class PhotonApiConfig {
    private PhotonApiConfig() {
    }

    //v1/devices/3e002e000a47343432313031/setTemp?access_token=
    public static final String BASE_API = "https://api.particle.io/";
    public static final String DEVICE_ID = "3e002e000a47343432313031";
    public static final String TOKEN = "09730cbdfa2ad80cefeaaf318e4cf6547d8ee443";
}
