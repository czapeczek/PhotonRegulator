package com.czapeczka.controllertest.api.retrofit;

import com.czapeczka.controllertest.api.PhotonApiConfig;
import com.czapeczka.controllertest.api.model.SetTempResponse;

import retrofit.http.Field;
import retrofit.http.FormUrlEncoded;
import retrofit.http.POST;
import rx.Observable;

/**
 * Created by Damian Walczak on 14/12/15.
 */
public interface PhotonApiService {

    @POST("v1/devices/" + PhotonApiConfig.DEVICE_ID + "/setTemp?access_token=" + PhotonApiConfig.TOKEN)
    @FormUrlEncoded
    Observable<SetTempResponse> setTemp(@Field("args") int temp);
}
