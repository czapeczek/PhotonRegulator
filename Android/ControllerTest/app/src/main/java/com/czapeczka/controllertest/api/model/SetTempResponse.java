package com.czapeczka.controllertest.api.model;

import com.google.gson.annotations.SerializedName;

/**
 * Created by Damian Walczak on 14/12/15.
 */
public class SetTempResponse {
    String id;
    boolean connected;

    @SerializedName("last_app")
    String lastApp;

    @SerializedName("return_value")
    int returnValue;

    public String getId() {
        return id;
    }

    public boolean isConnected() {
        return connected;
    }

    public String getLastApp() {
        return lastApp;
    }

    public int getReturnValue() {
        return returnValue;
    }
}
