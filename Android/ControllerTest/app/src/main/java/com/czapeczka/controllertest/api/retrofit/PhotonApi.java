package com.czapeczka.controllertest.api.retrofit;

import com.czapeczka.controllertest.api.PhotonApiConfig;
import com.czapeczka.controllertest.api.model.SetTempResponse;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.squareup.okhttp.OkHttpClient;

import retrofit.GsonConverterFactory;
import retrofit.Retrofit;
import retrofit.RxJavaCallAdapterFactory;
import rx.Observable;

/**
 * Created by Damian Walczak on 14/12/15.
 */
public class PhotonApi {
    private static class Holder {
        private static final PhotonApi INSTANCE = new PhotonApi();
    }

    private final PhotonApiService photonApiService;

    public static PhotonApi get() {
        return Holder.INSTANCE;
    }

    private PhotonApi() {
        Gson gson = new GsonBuilder().create();

        OkHttpClient client = new OkHttpClient();

        Retrofit.Builder retrofitBuilder = new Retrofit.Builder();
        retrofitBuilder
                .addConverterFactory(GsonConverterFactory.create(gson))
                .addCallAdapterFactory(RxJavaCallAdapterFactory.create())
                .baseUrl(PhotonApiConfig.BASE_API)
                .client(client);

        Retrofit retrofit = retrofitBuilder.build();
        photonApiService = retrofit.create(PhotonApiService.class);
    }

    public Observable<SetTempResponse> setTemperature(int newTemp) {
        return photonApiService.setTemp(newTemp);
    }
}
